#include <cmath>

#include "addition.hpp"

#define BASE_MIN 2
#define BASE_MAX 36

std::string Addition::add(const std::string& base_a, const std::string& number_a, const std::string& base_b, const std::string& number_b, const std::string& base_c) const {
	int decimal_base_c = convertToDecimal(10, base_c);
	if (decimal_base_c < BASE_MIN || decimal_base_c > BASE_MAX) {
		throw "Out of range";
	}

	int decimal_number_a = convertToDecimal(convertToDecimal(10, base_a), number_a);
	int decimal_number_b = convertToDecimal(convertToDecimal(10, base_b), number_b);
	return convertToString(decimal_base_c, decimal_number_a + decimal_number_b);
}

int Addition::convertToDecimal(int base, const std::string& number) const {
	if (base < BASE_MIN || base > BASE_MAX) {
		throw "Out of range";
	}

	size_t length = number.length();

	for (int i = 0; i < length; ++i) {
		if ((number[i] < '0' || number[i] > '9') && (number[i] < 'A' || number[i] > 'Z')) {
			throw "Out of range";
		}
	}

	int result{ 0 };

	for (int i = 0; i < length; ++i) {
		char digit = number[(length - 1) - i];
		int value = std::isdigit(digit) ? digit - '0' : std::toupper(digit) - 'A' + 10;
		result += value * static_cast<int>(std::pow(base, i));
	}

	return result;
}

std::string Addition::convertToString(int base, int number) const {
	if ((base < BASE_MIN || base > BASE_MAX) && (number < 0)) {
		throw "Out of range";
	}

	std::string result;

	while (number > 0) {
		int remains = number % base;

		if (remains < 10) {
			result += remains + '0';
		}

		else {
			result += remains + 'A' - 10;
		}

		number /= base;
	}

	std::reverse(result.begin(), result.end());

	return result;
}
