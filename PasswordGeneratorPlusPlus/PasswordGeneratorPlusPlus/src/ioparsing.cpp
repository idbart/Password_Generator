#include "ioparsing.h"
#include <regex>

// impliment this somehow
std::unordered_map<std::string, std::string> ioparsing::parse_cmd_args(int argc, char* argv[])
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
