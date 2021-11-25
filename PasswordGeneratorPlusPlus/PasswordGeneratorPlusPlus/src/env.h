#pragma once

// debug mode
#ifdef _DEBUG
	#define DEBUG true
#else
	#define DEBUG false
#endif // _DEBUG


//default rba options
#define DEFAULT_RBA_LENGTH 32

// default wordlist options
#define DEFAULT_WORDLIST_FILE_PATH myreflection::getExeDirPath().append("\\words.txt")

#define DEFAULT_WL_LENGTH mymath::getRandomIntInRange(3, 4)

#define DEFAULT_CAPS mymath::getRandomIntInRange(1, 3)

#define DEFAULT_PERMUTATIONS mymath::getRandomIntInRange(1, 3)

// default map of leet code
// source: https://www.gamehouse.com/blog/leet-speak-cheat-sheet/
#define DEFAULT_LEET_MAP { {'a', "@"}, {'b', "|3"}, {'c', "["}, {'d', "[)"}, {'e', "3"}, {'f', "|="}, {'g', "&"}, {'h', "]-["}, {'i', "!"}, {'j', "]"}, {'k', "|{"}, {'l', "|_"}, {'m', "/\\/\\"}, {'n', "|\\|"}, {'o', "0"}, {'p', "|*"}, {'q', "(_,)"}, {'r', "|?"}, {'s', "$"}, {'t', "']['"}, {'u', "(_)"}, {'v', "\\/"}, {'w', "\\/\\/"}, {'x', "}{"}, {'y', "'/"}, {'z', "%"} }

// usage string
#define USAGE "Usage: passgen [...OPTIONS]\n\
\n\
options:\n\
\t-h \tprint usage info\n\
\t-wl \twordlist path (deafults to current dir) \n\
\t-l \tpassword length (if in RBA mode, length is in bytes, if in worldlist mode, length is in words)\n\
\t-c \tnumber of capital letters (only applicable in wordlist mode)\n\
\t-p \tnumber of permutations (only applicable in wordlist mode)"

