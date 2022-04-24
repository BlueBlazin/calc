#include "ast.h"

Binary::Binary(BinOp op, std::unique_ptr<Expr> left,
               std::unique_ptr<Expr> right)
    : op(op),
      left(std::move(left)),
      right(std::move(right)),
      type(AstType::Binary) {}

AstType Binary::get_type() const { return AstType::Binary; }

Number::Number(double value) : value(value), type(AstType::Number) {}

AstType Number::get_type() const { return AstType::Number; }

std::ostream& operator<<(std::ostream& os, const BinOp& op) {
  switch (op) {
    case BinOp::Subtract:
      return os << "-";
    case BinOp::Add:
      return os << "+";
    case BinOp::Multiply:
      return os << "*";
    case BinOp::Divide:
      return os << "/";
  }
}

std::ostream& operator<<(std::ostream& os, const Expr& expr) {
  switch (expr.get_type()) {
    case AstType::Binary:
      return os << (Binary&)expr;
    case AstType::Number:
      return os << (Number&)expr;
  }
}

std::ostream& operator<<(std::ostream& os, const Binary& expr) {
  return os << "(" << *expr.left << " " << expr.op << " " << *expr.right << ")";
}

std::ostream& operator<<(std::ostream& os, const Number& expr) {
  return os << expr.value;
}

std::ostream& operator<<(std::ostream& os, const AstType& type) {
  switch (type) {
    case AstType::Binary:
      return os << "Binary";
    case AstType::Number:
      return os << "Number";
  }
}
