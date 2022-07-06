#pragma region Extra
#include <iostream>

#define PRINT(a) std::cout << a
#define PRINT2(a, b) std::cout << a << " " << b

#define PRINTLN(a) std::cout << a << std::endl
#define PRINT2LN(a, b) std::cout << a << " " << b << std::endl

#define TAB putchar('\t')
#define LN putchar('\n')
#define ENDL LN;
#pragma endregion

#include "logger.hpp"


int main(int argc, char** argv) {
	llcpp::logger::Logger* l = new llcpp::logger::Logger(".//logs");
	l->custom_log("test.txt", "%s %i", "Hola mundo!", 19212);
	l->custom_log("test.txt", "%s %i", "Hola mundo!", 19212);
	delete l;

	return 0;
}