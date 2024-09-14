#pragma once
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

enum TokenType {
    T_PLUS   = 0,
    T_MINUS  = 1,
    T_MULTI  = 2,
    T_DIV    = 3,
    T_INTLIT = 4
};

constexpr char *TokenStr[] = {"+", "-", "*", "/", "intlit"};

class Scanner {
public:
    explicit Scanner(const std::string &filename);
    ~Scanner();
    void work();

private:
    int  next();
    int  skip();
    void putback(int c);
    int  scanint(int c);
    int  chrops(const std::string &str, char target);
    struct Token {
        int token;
        int intvalue;
    };
    bool          scan(Token *t);
    std::ifstream _infile;
    int           _line;
    int           _putback;
};
