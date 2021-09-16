#pragma once

#include <string>

// type of password
// RBA meaning random byte array 
// WordList being a list of concatenated (and potentally prermuted) english words
enum PasswordType { RBA, WordList };

class Password
{
	// vars
private:
	std::string value;
	PasswordType type;
public:
	int capitalLetters;
	int permutes;

	// methods
private:

public:
	// constructors 
	// default constor?? 
	// i think not???
	Password(PasswordType type) : type(type) { };


	void Generate();
};

