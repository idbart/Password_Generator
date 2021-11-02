#include "env.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <format>
#include "Password.h"
#include "helper.h"


int main(int argc, char* argv[])
{
	// parse command line arguments
	std::unordered_map<std::string, std::string> args = myioparsing::parse_cmd_args(argc, argv);

#if DEBUG
	LOG("ARGS:");
	LOG("\tKEY:\tVALUE:");LOG("");
	for (std::pair<std::string, std::string> arg : args)
	{
		LOG(std::string("\t").append(arg.first).append("\t").append(arg.second));
	}
#endif

	// if the user sets the help option, print useage info
	if (args.find("-h") != args.end())
	{
		LOG(USAGE);
		return 0;
	}

	// init password
	// set type to wordlist if the user sets the -wl flag and to rba if not
	Password* password = nullptr;

	// set password options
	// set password type
	if (args.find("-wl") != args.end())
	{
		password = new Password(PasswordType::WordList);

#if DEBUG
		LOG("WORDLIST PATH: " << DEFAULT_WORDLIST_FILE_PATH);
#endif
		// set the password obj to use a file path input by the user if they input one
		// if not use the default path
		// if the file does not exist, print an error message and terminate
		if (password->UseWordlistFile(args["-wl"] == "" ? DEFAULT_WORDLIST_FILE_PATH : args["-wl"]) == false)
		{
			LOG_ERROR("Could not locate wordlist!");
			return -1;
		}
	}
	else
	{
		password = new Password(PasswordType::RBA);
	}

	// if the user specifies a length, use it
	if (args.find("-l") != args.end())
	{
		password->length = std::stoi(args["-l"]);
	}

	// if the user specifies a number of capital letters, use it
	if (args.find("-c") != args.end())
	{
		password->capitalLetters = std::stoi(args["-c"]);
	}

	// if the user specifies a number of permutations, use it
	if (args.find("-p") != args.end())
	{
		password->permutes = std::stoi(args["-p"]);
	}

	// generate password
	password->Generate();

#if DEBUG
	LOG("OUTPUT:");
#endif
	// print password to console
	LOG(password->GetValue());

#if DEBUG
	std::cin.get();
#endif

	delete password;
	return 0;
}