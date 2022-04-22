#pragma once

#include <cctype>
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

 public:
  Tokenizer(std::string filepath);

  Token Next();

  bool HasNext();

 private:
  void ScanWhitespace();

  Token ScanNumber(char start);
};

std::ostream& operator<<(std::ostream& os, const Token& token);