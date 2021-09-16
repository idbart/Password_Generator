#include <iostream>
#include <unordered_map>
#include <string>

#include "ioparsing.h"

int main(int argc, char* argv[])
{
	// parse cmd args into a hash map of key value pairs
	std::unordered_map<std::string, std::string> args = ioparsing::parse_cmd_args(argc, argv);
	
	for (std::pair<std::string, std::string> arg  : args)
	{

	}
}