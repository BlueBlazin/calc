#pragma once

#include <memory>

enum class BinOp { Subtract, Add, Multiply, Divide };

enum class AstType {
  Binary,
  Number,
};

class Expr {
 public:
  virtual ~Expr() {}
};

class Binary : public Expr {
 public:
  BinOp op;
  std::unique_ptr<Expr> left;
  std::unique_ptr<Expr> right;
  AstType type;

  Binary(BinOp op, std::unique_ptr<Expr> left, std::unique_ptr<Expr> right)
      : op(op),
        left(std::move(left)),
        right(std::move(right)),
        type(AstType::Binary) {}
};

class Number : public Expr {
 public:
  double value;
  AstType type;

  Number(double value) : value(value), type(AstType::Number) {}
};
