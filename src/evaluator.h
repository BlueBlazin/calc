#pragma once

#include <iostream>
#include <memory>

#include "ast.h"

double Eval(std::unique_ptr<Expr>& ast);

double EvalBinary(Binary& ast);

double EvalNumber(Number& ast);
