#include "parser.h"

Parser::Parser(Tokenizer& tokenizer) : tokenizer_(tokenizer) {}

std::unique_ptr<Expr> Parser::Parse() {
  std::unique_ptr<Expr> lhs = PrimaryExpr();

  // early exit if parsing lhs failed
  if (!lhs) {
    return lhs;
  }

  return PrecedenceClimbing(std::move(lhs), 1);
}

std::unique_ptr<Expr> Parser::PrimaryExpr() {
  Token token = tokenizer_.Next();

  switch (token.type) {
    case TokenType::Number:
      return std::unique_ptr<Expr>(new Number(token.value));
    default:
      return std::unique_ptr<Expr>(nullptr);
  }
}

std::unique_ptr<Expr> Parser::PrecedenceClimbing(std::unique_ptr<Expr> lhs,
                                                 int precedence) {
  if (!tokenizer_.HasNext()) {
    return lhs;
  }

  Token& next_token = tokenizer_.Peek();

  while (Precedence(next_token) >= precedence) {
    Token op = tokenizer_.Next();
    std::unique_ptr<Expr> rhs = PrimaryExpr();

    while (tokenizer_.HasNext() &&
           Precedence(tokenizer_.Peek()) > Precedence(op)) {
      rhs = PrecedenceClimbing(std::move(rhs), Precedence(tokenizer_.Peek()));

      if (tokenizer_.HasNext()) {
        next_token = tokenizer_.Peek();
      }
    }

    lhs = std::unique_ptr<Expr>(
        new Binary(GetBinOp(op), std::move(lhs), std::move(rhs)));
  }
}

BinOp Parser::GetBinOp(Token& op) {
  switch (op.type) {
    case TokenType::Minus:
      return BinOp::Subtract;
    case TokenType::Plus:
      return BinOp::Add;
    case TokenType::Star:
      return BinOp::Multiply;
    case TokenType::Slash:
      return BinOp::Divide;
  }
}

int Parser::Precedence(Token& token) {
  switch (token.type) {
    case TokenType::Minus:
    case TokenType::Plus:
      return 1;
    case TokenType::Star:
    case TokenType::Slash:
      return 2;
    default:
      return 0;
  }
}
