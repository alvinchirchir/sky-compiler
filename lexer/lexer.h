#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "../token/token.h"

class Lexer {
public:
    Lexer(const std::string& source);
    Token getNextToken();

private:
    std::string source;
    size_t currentPos;
};

#endif // LEXER_H
