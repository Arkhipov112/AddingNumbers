#pragma once
#include <fstream>
#include <string>

#define NUMBER_ELEMENTS 5

class Parser final {
public:
	Parser(const std::string& path);

	void read();
	void write(const std::string& result);

	void split();

	// [0] = base_a, [1] = number_a, [2] = base_b, [3] = number_b, [4] = base_c
	std::string result[NUMBER_ELEMENTS];

private:
	std::string path;
	std::string text;
};
