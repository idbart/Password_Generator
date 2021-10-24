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
	void GenerateRBAPW();
	void GenerateWordListPW();
	static bool CapitalizeChar(std::string& word);
	static bool PermuteChar(std::string& word);

public:
	// constructors 
	// default constor?? 
	// i think not???
																											// if the user does not provide a length, make it 4 words or 32 chars
	Password(PasswordType type) : type(type), value(""), wordlistFilePath(""), capitalLetters(0), permutes(0) { this->length = type == PasswordType::WordList ? 4 : 32; };
	Password(PasswordType type, int length, int capitalLetters, int permutes) : type(type), length(length), wordlistFilePath(""), capitalLetters(capitalLetters), permutes(permutes) { };

	bool UseWordlistFile(const std::string& path);
	const std::string& GetValue() const { return this->value; }
	void Generate();
};

