#pragma once

#define DEBUG true

#define DEFAULT_WORDLIST_FILE_PATH "./"

#define USAGE "Usage: passgen [...OPTIONS]\n\
\n\
options:\n\
\t-h \tprint usage info\n\
\t-wl \twordlist mode \n\
\t-l \tpassword length (if in RBA mode, length is in bytes, if in worldlist mode, length is in words)\n\
\t-c \tnumber of capital letters (only applicable in wordlist mode)\n\
\t-p \tnumber of permutations (only applicable in wordlist mode)"
