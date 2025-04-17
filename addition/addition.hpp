#pragma once
#include <string>

class Addition final {
public:
	std::string add(const std::string& base_a, const std::string& number_a, const std::string& base_b, const std::string& number_b, const std::string& base_c) const;

private:
	int convertToDecimal(int base, const std::string& number) const;
	std::string convertToString(int base, int number) const;
};
