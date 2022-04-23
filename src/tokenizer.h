#pragma once

#include <cctype>
#include <memory>
#include <optional>
#include <ostream>

#include "reader.h"

enum class TokenType {
  Number,
  Plus,
  Minus,
  Star,
  Slash,
};

struct Token {
  TokenType type;
  double value;
};

class Tokenizer {
 private:
  Reader reader_;
  std::optional<Token> buffer_;

 public:
  Tokenizer(std::string filepath);

  Token Next();

  bool HasNext();

  Token& Peek();

 private:
  void ScanWhitespace();

  Token ScanNumber(char start);
};

std::ostream& operator<<(std::ostream& os, const Token& token);
