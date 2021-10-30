#include "Password.h"
#include "env.h"
#include <random>
#include <algorithm>
#include <fstream>
#include <vector>
#include "helper.h"


Password::Password(PasswordType type) : _type(type), _wordlistFilePath("")
{
	if (type == PasswordType::WordList)
	{
		this->length = DEFAULT_WL_LENGTH;
		this->capitalLetters = DEFAULT_CAPS;
		this->permutes = DEFAULT_PERMUTATIONS;
	}
	else if (type == PasswordType::RBA)
	{
		this->length = DEFAULT_RBA_LENGTH;
	}
}

// set the file path for the word list file to be used by this class
bool Password::UseWordlistFile(const std::string& path)
{
	// just check if the file exists, and if it does use it
	if (std::ifstream(path).good())
	{
		this->_wordlistFilePath = path;
		return true;
	}
	else
	{
		return false;
	}
}

// generate the password
void Password::Generate()
{
	if (this->_type == PasswordType::RBA)
	{
		this->GenerateRBAPW();
	}
	else if (this->_type == PasswordType::WordList)
	{
		this->GenerateWordListPW();
	}
}

// generate a rba password
void Password::GenerateRBAPW()
{
	// init the char array for the password
	// force dynamic allocation on the stack because i feel like it 
	char* password = (char*)alloca((sizeof(char) * this->length) + 1);

	for (int i = 0; i < this->length; i++)
	{
		// get random int and static cast to char type for each char in password
		// get random int between 33 and 126 because those are the values that corilate to actual charactes in the ASCII standard (as opposed to other wacky crap like tabs and escape chars)
		password[i] = (char)mymath::getRandomIntInRange(33, 126);
	}

	password[this->length] = '\0';
	this->_value = std::string(password);
}

void Password::GenerateWordListPW()
{
	// lets be real, what the hell is this?
	// theres gota be a more effiecent way
	// figure it out later
	std::vector<std::string> words = myfileio::getFileLines(this->_wordlistFilePath);

	std::vector<std::string> passwords = std::vector<std::string>(this->length);
	int charLength = 0;

#if DEBUG
	LOG("WORDS:");
#endif

	// pick the words
	for (int i = 0; i < this->length; i++)
	{
		std::string word = words[mymath::getRandomIntInRange(0, words.size() - 1)];
		passwords[i] = word;

#if DEBUG
		std::cout << word << '\t';
#endif

		charLength += word.length();
	}

#if DEBUG
	std::cout << std::endl;
#endif

	// if the total char count of the password is not enough to satisfy the users requested caps and perms, return for now
	// maybe in the future just do as many as possible or roll the dice on the words agian and hope for more chars????
	if (this->capitalLetters + this->permutes > charLength) return;

	// add capital letters
	for (int i = 0; i < this->capitalLetters; i++)
	{
		while (true)
		{
			if (Password::CapitalizeChar(passwords[mymath::getRandomIntInRange(0, this->length - 1)])) break;
		}
	}

	// concat all the words together to make the password string
	std::string password = "";
	for (int i = 0; i < this->length; i++)
	{
		password.append(passwords[i]);
	}

#if DEBUG
	if(this->permutes > 0) LOG("LEET PERMUTATIONS:");
#endif
	// add permutes
	for (int i = 0; i < this->permutes; i++)
	{
		while (true)
		{
			if (Password::PermuteChar(password)) break;
		}
	}

	// set the _value field to the final password
	this->_value = password;
}

// check if a string is permutable
// meaning check if the string is not already entirely made up of capital letters and special chars
bool Password::IsPermutable(std::string& string)
{
	return string.length() > 0 && !std::all_of(string.begin(), string.end(), [](unsigned char symbol) { return !std::isalpha(symbol) || std::isupper(symbol); });
}

// capitalize one letter in a word
bool Password::CapitalizeChar(std::string& word)
{
	if (Password::IsPermutable(word))
	{
		// always capitaize first letter if not already capitaized
		int nextTry = 0;
		while (true)
		{
			if (std::isalpha(word[nextTry]) && !std::isupper(word[nextTry]))
			{
				word[nextTry] = std::toupper(word[nextTry]);
				break;
			}

			// if already caped, pick a random index to try next
			nextTry = mymath::getRandomIntInRange(1, word.length() - 1);
		}

		return true;
	}
	else
	{
		return false;
	}
}

bool Password::PermuteChar(std::string& string)
{
	if(Password::IsPermutable(string)) 
	{
		static std::unordered_map<char, std::string> leetAlpha = DEFAULT_LEET_MAP;

		while (true)
		{
			// pick a random index and permute it if its not already capitalized
			int charIndex = mymath::getRandomIntInRange(0, string.length() - 1);
			char letter = string[charIndex];
			if (std::isalpha(letter) && !std::isupper(letter))
			{
				std::string leetChar = leetAlpha[letter];
				string.replace(charIndex, 1, leetChar);

#if DEBUG
				LOG('\t' << letter << '\t' << leetChar);
#endif
				break;
			}
		}

		return true;
	}
	else
	{
		return false;
	}
}