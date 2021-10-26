#pragma once

#include <string>

// type of password
// RBA meaning random byte array 
// WordList being a list of concatenated (and potentally prermuted) english words
enum class PasswordType { RBA, WordList };

class Password
{
	// vars
private:
	std::string _value;
	PasswordType _type;
	std::string _wordlistFilePath;

public:
	int length;
	int capitalLetters;
	int permutes;

	// methods
private:
	void GenerateRBAPW();
	void GenerateWordListPW();
	static bool CapitalizeChar(std::string& word);
	static bool PermuteChar(std::string& word);

public:
	// constructors 
	// default constor?? 
	// i think not???
		
	// change this constructor later to use a random length for wordlist passwords and a random ammount of cap and perms 
																									// if the user does not provide a length, make it 4 words or 32 chars
	Password(PasswordType type);
	Password(PasswordType type, int length, int capitalLetters, int permutes) : _type(type), length(length), _wordlistFilePath(""), capitalLetters(capitalLetters), permutes(permutes) { };

	bool UseWordlistFile(const std::string& path);
	const std::string& GetValue() const { return this->_value; }
	void Generate();
};

