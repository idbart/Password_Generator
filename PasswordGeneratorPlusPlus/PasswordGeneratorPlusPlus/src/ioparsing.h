#pragma once

#include <unordered_map>
#include <string>

namespace ioparsing
{
	std::unordered_map<std::string, std::string> parse_cmd_args(int argc, char* argv[]);
}