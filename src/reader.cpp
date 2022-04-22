#include "reader.h"

Reader::Reader(std::string filepath) : file_(filepath), it_(file_) {}

char Reader::Next() {
  char c = *it_;
  it_++;

  return c;
}

char Reader::Peek() { return *it_; }

bool Reader::HasNext() { return it_ != std::istreambuf_iterator<char>(); }
