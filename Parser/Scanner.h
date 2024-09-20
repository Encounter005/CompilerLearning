#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>

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
    void run();

private:
    int  next();
    int  skip();
    void putback(int c);
    int  scanint(int c);
    int  chrops(const std::string &str, char target);
    void handle_error(const std::string &message);
    struct Token {
        int token;
        int intvalue;
    };
    bool          scan(Token *t);
    std::ifstream _infile;
    int           _line;
    int           _putback;
};
