#include "Scanner.h"

Scanner::Scanner(const std::string &filename)
    : _infile(filename), _line(1), _putback('\n') {
    if (!_infile.is_open()) {
        handle_error(
            "Unable to open file: " + filename + " "
            + std::string(strerror(errno)));
    }
}

Scanner::~Scanner() {
    _infile.close();
}

int Scanner::next() {
    int c;
    if (_putback) {
        c        = _putback;
        _putback = 0;
        return c;
    }

    c = _infile.get();
    if ('\n' == c) {
        _line++;
    }
    return c;
}

int Scanner::skip() {
    int c;
    do {
        c = next();
    } while ('\n' == c || '\t' == c || '\r' == c || '\f' == c || ' ' == c);
    return c;
}

void Scanner::putback(int c) {
    _putback = c;
}


int Scanner::chrops(const std::string &str, char target) {
    auto pos = str.find(target);
    return pos == std::string::npos ? -1 : pos;
}

int Scanner::scanint(int c) {
    int val = 0, tmp = 0;

    while ((tmp = chrops("0123456789", c)) >= 0) {
        val = val * 10 + tmp;
        c   = next();
    }

    putback(c);

    return val;
}

bool Scanner::scan(Token *t) {
    auto c = skip();
    switch (c) {
    case EOF: return false;
    case '+': t->token = T_PLUS; break;
    case '-': t->token = T_MINUS; break;
    case '/': t->token = T_DIV; break;
    case '*': t->token = T_MULTI; break;
    default:
        if (isdigit(c)) {
            t->intvalue = scanint(c);
            t->token    = T_INTLIT;
            break;
        }

        handle_error(
            "Unrecognized character: " + std::to_string(c)
            + " on line: " + std::to_string(_line));
    }

    return true;
}

void Scanner::run() {
    struct Token token;
    while (scan(&token)) {
        std::cout << "Token: " << TokenStr[token.token];
        if (token.token == T_INTLIT) {
            std::cout << " Value: " << token.intvalue;
        }
        std::cout << std::endl;
    }
}

void Scanner::handle_error(const std::string &message) {
    std::cerr << "Error: " << message << std::endl;
    std::exit(1);
}
