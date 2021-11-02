#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#define LOG(x) std::cout << x << std::endl
#define LOG_ERROR(x) LOG(std::string("ERROR: ").append(x))

namespace myioparsing
{
	std::unordered_map<std::string, std::string> parse_cmd_args(int argc, char* argv[]);
}

namespace myfileio
{
	const std::vector<std::string> getFileLines(const std::string& filePath);
}

namespace mymath
{
	unsigned int getRandomIntInRange(unsigned int lower, unsigned int upper);
}

namespace myreflection
{
	std::string getExeDirPath();
}
