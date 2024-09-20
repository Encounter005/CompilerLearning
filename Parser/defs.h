#pragma once
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token {
    int token;
    int intvalue;
};

// Tokens
enum {
    T_EOF    = 0,
    T_PLUS   = 1,
    T_MINUS  = 2,
    T_MUL    = 3,
    T_SLASH  = 4,
    T_INTLIT = 5
};


enum { A_ADD = 0, A_SUBTRACT = 1, A_MULTIPLY = 2, A_DIVIDE = 3, A_INTLIT = 4 };

struct ASTnode {
    struct ASTnode *left;
    struct ASTnode *right;
    int             op;   // operation
    int             intvalue;
};
