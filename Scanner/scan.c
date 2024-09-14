#include "data.h"
#include "defs.h"

static int next() {
    int c;

    if (Putback) {
        c       = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);
    if ('\n' == c) {
        Line++;
    }

    return c;
}

// Put back an unwanted character
static void putback(int c) {
    Putback = c;
}

// Ignoring whitespace
// @return return the first character we want to process
static int skip() {
    int c;
    c = next();
    while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
        c = next();
    }
    return c;
}

// @return the pos in the str or -1 if not found
static int chrpos(char *str, int c) {
    char *p;
    p = strchr(str, c);
    return p ? p - str : -1;
}

// Scan and return an integer
static int scanint(int c) {
    int k, val = 0;

    while ((k = chrpos("0123456789", c)) >= 0) {
        val = val * 10 + k;
        c   = next();
    }

    // hit a non-integer character, put it back
    putback(c);
    return val;
}

// @return 1 if token valid, 0 if no tokens left.
int scan(struct token *t) {
    int c;
    // get the first character skipping the whitespace
    c = skip();
    switch (c) {
    case EOF: return 0;
    case '+': t->token = T_PLUS; break;
    case '-': t->token = T_MINUS; break;
    case '*': t->token = T_MUL; break;
    case '/': t->token = T_SLASH; break;
    default:
        if (isdigit(c)) {
            t->intvalue = scanint(c);
            t->token    = T_INTLIT;
            break;
        }
        printf("Unrecognised character: %c on Line: %d\n", c, Line);
        exit(1);
    }

    // found the token;
    return 1;
}
