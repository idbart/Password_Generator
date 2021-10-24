#pragma once


#define DEBUG true

#define DEFAULT_WORDLIST_FILE_PATH "./words.txt"

#define DEFAULT_LEET_MAP { {'a', "@"}, {'b', "|3"}, {'c', "["}, {'d', "[)"}, {'e', "3"}, {'f', "|="}, {'g', "&"}, {'h', "]-["}, {'i', "!"}, {'j', "]"}, {'k', "|{"}, {'l', "|_"}, {'m', "/\\/\\"}, {'n', "|\\|"}, {'o', "0"}, {'p', "|*"}, {'q', "(_,)"}, {'r', "|?"}, {'s', "$"}, {'t', "']['"}, {'u', "(_)"}, {'v', "\\/"}, {'w', "\\/\\/"}, {'x', "}{"}, {'y', "'/"}, {'z', "%"} }

#define USAGE "Usage: passgen [...OPTIONS]\n\
\n\
options:\n\
\t-h \tprint usage info\n\
\t-wl \twordlist path (deafults to current dir) \n\
\t-l \tpassword length (if in RBA mode, length is in bytes, if in worldlist mode, length is in words)\n\
\t-c \tnumber of capital letters (only applicable in wordlist mode)\n\
\t-p \tnumber of permutations (only applicable in wordlist mode)"

