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
	std::string value;
	PasswordType type;
	std::string wordlistFilePath;

public:
	int length;
	int capitalLetters;
	int permutes;

	// methods
private:

public:
	// constructors 
	// default constor?? 
	// i think not???
	Password(PasswordType type) : type(type), value(""), wordlistFilePath(""), capitalLetters(0), permutes(0) { this->length = type == PasswordType::WordList ? 4 : 32; };
	Password(PasswordType type, int length, int capitalLetters, int permutes) : type(type), length(length), wordlistFilePath(""), capitalLetters(capitalLetters), permutes(permutes) { };

	bool UseWordlistFile(const std::string& path);
	const std::string& GetValue() const { return this->value; }
	void Generate();
};

