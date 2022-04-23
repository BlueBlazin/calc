#pragma once

#include <memory>
#include <ostream>

enum class BinOp { Subtract, Add, Multiply, Divide };

enum class AstType {
  Binary,
  Number,
};

class Expr {
 public:
  virtual AstType get_type() const = 0;

  virtual ~Expr() {}
};

class Binary : public Expr {
 public:
  BinOp op;
  std::unique_ptr<Expr> left;
  std::unique_ptr<Expr> right;
  AstType type;

  Binary(BinOp op, std::unique_ptr<Expr> left, std::unique_ptr<Expr> right);

  AstType get_type() const override;
};

class Number : public Expr {
 public:
  double value;
  AstType type;

  Number(double value);

  AstType get_type() const override;
};

std::ostream& operator<<(std::ostream& os, const BinOp& op);

std::ostream& operator<<(std::ostream& os, const Expr& expr);

std::ostream& operator<<(std::ostream& os, const Binary& expr);

std::ostream& operator<<(std::ostream& os, const Number& expr);

std::ostream& operator<<(std::ostream& os, const AstType& expr);
