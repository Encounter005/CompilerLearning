#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct token {
    int token;
    int intvalue;
};

// Tokens
enum {
    T_PLUS = 0,
    T_MINUS = 1,
    T_MUL = 2,
    T_SLASH = 3,
    T_INTLIT = 4
};


