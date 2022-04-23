#include "tokenizer.h"

Tokenizer::Tokenizer(std::string filepath) : reader_(filepath), buffer_() {}

Token& Tokenizer::Peek() {
  if (buffer_.has_value()) {
    return buffer_.value();
  }

  buffer_ = Next();

  return buffer_.value();
}

Token Tokenizer::Next() {
  if (buffer_.has_value()) {
    // extract token out of optional
    Token token = *std::move(buffer_);
    // reset optional so it's empty again
    buffer_.reset();

    return token;
  }

  ScanWhitespace();

  char start;

  switch (start = reader_.Next()) {
    case '+':
      return Token{
          .type = TokenType::Plus,
          .value = NULL,
      };
    case '-':
      return Token{
          .type = TokenType::Minus,
          .value = NULL,
      };
    case '*':
      return Token{
          .type = TokenType::Star,
          .value = NULL,
      };
    case '/':
      return Token{
          .type = TokenType::Slash,
          .value = NULL,
      };
    default:
      return ScanNumber(start);
  }
}

Token Tokenizer::ScanNumber(char start) {
  std::string n{start};

  while (reader_.HasNext() && std::isdigit(reader_.Peek())) {
    n += reader_.Next();
  }

  return Token{
      .type = TokenType::Number,
      .value = std::stod(n),
  };
}

bool Tokenizer::HasNext() {
  ScanWhitespace();
  return reader_.HasNext();
}

void Tokenizer::ScanWhitespace() {
  while (reader_.HasNext() && std::isspace(reader_.Peek())) {
    reader_.Next();
  }
}

std::ostream& operator<<(std::ostream& os, const Token& token) {
  switch (token.type) {
    case TokenType::Minus:
      return os << "Token(-)";
    case TokenType::Plus:
      return os << "Token(+)";
    case TokenType::Star:
      return os << "Token(*)";
    case TokenType::Slash:
      return os << "Token(/)";
    case TokenType::Number:
      return os << "Token(" << token.value << ")";
  }
}
