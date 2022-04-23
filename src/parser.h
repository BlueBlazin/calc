#pragma once

#include <memory>

#include "ast.h"
#include "tokenizer.h"

class Parser {
 private:
  Tokenizer& tokenizer_;

 public:
  Parser(Tokenizer& tokenizer);

  std::unique_ptr<Expr> Parse();

 private:
  std::unique_ptr<Expr> PrimaryExpr();

  std::unique_ptr<Expr> PrecedenceClimbing(std::unique_ptr<Expr> lhs,
                                           int precedence);

  int Precedence(Token& token);

  BinOp GetBinOp(Token& op);
};
