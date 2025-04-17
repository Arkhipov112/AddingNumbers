#include "parser.hpp"

Parser::Parser(const std::string& path) : path(path) {}

void Parser::read() {
	std::ifstream in(path);
	if (!in.is_open()) {
		throw "Couldn't open the file";
	}

	std::string line;
	while (std::getline(in, line)) {
		text += line + '\n';
	}
	text.pop_back();

	in.close();
}

void Parser::write(const std::string& result) {
	std::ofstream out(path);
	if (!out.is_open()) {
		throw "Couldn't open the file";
	}

	out << text;
	out << ':' << ' ' << '\"' << result << '\"';

	out.close();
}

void Parser::split() {
	for (int i = 0, j = 0; i < text.length(); ++i) {
		if ((text[i] == '\"') || (text[i] == ' ')) {
			continue;
		}

		if ((text[i] == ':') || (text[i] == '\n')) {
			++j;
			continue;
		}

		result[j] += text[i];
	}
}
