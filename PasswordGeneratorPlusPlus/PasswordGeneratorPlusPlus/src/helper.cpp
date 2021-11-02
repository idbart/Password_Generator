#include "helper.h"
#include <Windows.h>
#include <regex>
#include <fstream>
#include <random>

// impliment this somehow
std::unordered_map<std::string, std::string> myioparsing::parse_cmd_args(int argc, char* argv[])
{
	std::unordered_map<std::string, std::string> args = std::unordered_map<std::string, std::string>();

	std::regex optionRegex = std::regex("^-[a-z]+$", std::regex_constants::icase);
	for (int i = 1; i < argc; i++)
	{
		if (std::regex_search(argv[i], optionRegex))
		{
			if (i < argc - 1 && !std::regex_search(argv[i + 1], optionRegex))
			{
				args[argv[i]] = argv[i + 1];
			}
			else
			{
				args[argv[i]] = "";
			}
		}
	}

	return args;
}

const std::vector<std::string> myfileio::getFileLines(const std::string& filePath)
{
	std::ifstream fileStream = std::ifstream(filePath);
	std::vector<std::string> lines = std::vector<std::string>();

	if (fileStream.good())
	{
		std::string tempStr;
		while (std::getline(fileStream, tempStr))
		{
			lines.push_back(tempStr);
		}
	}
	
	fileStream.close();
	return lines;
}

unsigned int mymath::getRandomIntInRange(unsigned int lower, unsigned int upper)
{
	if (upper > lower)
	{
		static std::default_random_engine rng;

		static bool seeded = false;
		if (!seeded)
		{
			std::random_device rd;
			rng.seed(rd());

			seeded = true;
		}

		unsigned int rbytes = rng();

		unsigned int difference = upper - lower;
		return (rbytes % (difference + 1)) + lower;
	}
	else
	{
		return 0;
	}
}

std::string myreflection::getExeDirPath()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");

	return std::string(buffer).substr(0, pos);
}
