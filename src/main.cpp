#include "tokenizer.h"

int main() {
  Tokenizer tokenizer("../input.txt");

  while (tokenizer.HasNext()) {
    std::cout << tokenizer.Next() << std::endl;
  }

  return EXIT_SUCCESS;
}

// #include <fstream>
// #include <iostream>
// #include <iterator>

// class Foo {
//  private:
//   std::ifstream file;
//   std::istreambuf_iterator<char> it_;

//  public:
//   Foo(std::string filepath) : file(filepath), it_(file) {}

//   char Next() {
//     char c = *it_;
//     it_++;

//     return c;
//   }

//   bool HasNext() { return it_ != std::istreambuf_iterator<char>(); }
// };

// int main() {
//   Foo foo("../input.txt");

//   while (foo.HasNext()) {
//     std::cout << foo.Next();
//   }

//   std::cout << std::endl;

//   return EXIT_SUCCESS;
// }

// #include <fstream>
// #include <iostream>
// #include <iterator>

// class Foo {
//  private:
//   std::ifstream file;
//   std::istream_iterator<char> it_;

//  public:
//   Foo(std::string filepath) : file(filepath), it_(file) {}

//   char Next() {
//     char c = *it_;
//     it_++;
//     return c;
//   }

//   bool HasNext() { return it_ != std::istream_iterator<char>(); }
// };

// int main() {
//   Foo foo("../input.txt");

//   while (foo.HasNext()) {
//     std::cout << foo.Next();
//   }

//   std::cout << std::endl;

//   return EXIT_SUCCESS;
// }

// #include "reader.h"

// int main() {
//   Reader reader("../input.txt");

//   // while (reader.HasNext()) {
//   //   std::cout << "'" << reader.Next() << "', ";
//   // }

//   std::cout << reader.HasNext() << std::endl;
//   std::cout << reader.Next() << std::endl;
//   // std::cout << reader.HasNext() << std::endl;
//   // std::cout << reader.Next() << std::endl;

//   return EXIT_SUCCESS;
// }

// #include <fstream>
// #include <iostream>
// #include <iterator>

// int main() {
//   std::ifstream file("../input.txt");
//   std::istream_iterator<char> reader(file);

//   while (reader != std::istream_iterator<char>()) {
//     char c = *reader;
//     reader++;
//     std::cout << "'" << c << "', ";
//   }

//   std::cout << std::endl;

//   return EXIT_SUCCESS;
// }

// int main() {
//   vector<char> bytes;
//   char byte = 0;

//   std::ifstream input_file("../input.txt");

//   if (!input_file.is_open()) {
//     std::cerr << "Could not open file" << std::endl;
//     return EXIT_FAILURE;
//   }

//   while (input_file.get(byte)) {
//     bytes.push_back(byte);
//   }

//   for (char c : bytes) {
//     std::cout << '\'' << c << '\'' << ", ";
//   }
//   std::cout << std::endl;

//   return EXIT_SUCCESS;
// }
