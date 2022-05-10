#include "evaluator.h"

double Eval(std::unique_ptr<Expr>& ast) {
  switch (ast->get_type()) {
    case AstType::Binary:
      return EvalBinary(static_cast<Binary&>(*ast));
    case AstType::Number:
      return EvalNumber(static_cast<Number&>(*ast));
  }
}

double EvalBinary(Binary& ast) {
  double lhs = Eval(ast.left);
  double rhs = Eval(ast.right);

  switch (ast.op) {
    case BinOp::Add:
      return lhs + rhs;
    case BinOp::Subtract:
      return lhs - rhs;
    case BinOp::Multiply:
      return lhs * rhs;
    case BinOp::Divide:
      return lhs / rhs;
  }
}

double EvalNumber(Number& ast) { return ast.value; }
