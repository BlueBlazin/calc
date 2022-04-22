#pragma once

#include <fstream>
#include <iostream>
#include <iterator>

class Reader {
 private:
  std::ifstream file_;
  std::istreambuf_iterator<char> it_;

 public:
  Reader(std::string filepath);

  char Next();

  char Peek();

  bool HasNext();
};
