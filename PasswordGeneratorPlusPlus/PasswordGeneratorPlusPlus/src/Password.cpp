#include "Password.h"
#include "env.h"
#include <random>
#include <fstream>
#include <vector>
#include "helper.h"


bool Password::UseWordlistFile(const std::string& path)
{
	// just check if the file exists, and if it does use it
	if (std::ifstream(path).good())
	{
		this->wordlistFilePath = path;
		return true;
	}
	else
	{
		return false;
	}
}


void Password::Generate()
{
	if (this->type == PasswordType::RBA)
	{
		this->GenerateRBAPW();
	}
	else if (this->type == PasswordType::WordList)
	{
		this->GenerateWordListPW();
	}
}


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
	this->value = std::string(password);
}

void Password::GenerateWordListPW()
{
	// lets be real, what the hell is this?
	// theres gota be a more effiecent way
	// figure it out later
	std::vector<std::string> words = myfileio::getFileLines(this->wordlistFilePath);

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

	// set the value field to the final password
	this->value = password;
}

// capitalize one letter in a word

// this needs more error handeling in the future
// if the given word is already fully capitaized or is all non-alphabetic this method will create an infinite loop
bool Password::CapitalizeChar(std::string& word)
{
	if (word.length() > 0)
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
	std::unordered_map<char, std::string> leetAlpha = DEFAULT_LEET_MAP;

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