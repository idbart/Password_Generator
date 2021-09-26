#include "Password.h"
#include <random>
#include <fstream>



bool Password::UseWordlistFile(const std::string& path)
{
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
	std::default_random_engine rng = std::default_random_engine();

	if (this->type == PasswordType::RBA)
	{
		char* password = (char*)alloca((sizeof(char) * this->length) + 1);

		for (int i = 0; i < this->length; i++)
		{
			password[i] = (char)rng();
		}

		password[this->length] = '\0';
		this->value = std::string(password);
	}
	else if (this->type == PasswordType::WordList)
	{

	}
}