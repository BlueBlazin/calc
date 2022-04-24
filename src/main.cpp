#include <iostream>
#include <memory>

#include "ast.h"
#include "evaluator.h"
#include "parser.h"
#include "tokenizer.h"

int main() {
  Tokenizer tokenizer("../input.txt");
  Parser parser(tokenizer);

  std::unique_ptr<Expr> ast = parser.Parse();

  std::cout << *ast << " = " << Eval(ast) << std::endl;

  return EXIT_SUCCESS;
}
