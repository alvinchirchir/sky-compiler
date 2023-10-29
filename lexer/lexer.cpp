#include "lexer.h"
#include <iostream>
#include "../node/node.h"

Lexer::Lexer(const std::string& source) : source(source), currentPos(0) {}

Token Lexer::getNextToken() {

    if (currentPos >= source.length()) {
        return {END_OF_FILE, ""};
    }

    char c = source[currentPos++];
    switch (c) {
        case '=':
            return {ASSIGN, "="};
        case ';':
            return {SEMICOLON, ";"};
        default:
            if (isalpha(c)) {
                source[--currentPos]; // Un-consume the first character of the variable
                std::string lexeme;
                while (currentPos < source.length() && (isalnum(source[currentPos]) || source[currentPos] == '_')) {
                    lexeme += source[currentPos++];
                }
                return {VARIABLE, lexeme};
            } else if (isdigit(c)) {
                source[--currentPos]; // Un-consume the first character of the number
                std::string lexeme;
                while (currentPos < source.length() && isdigit(source[currentPos])) {
                    lexeme += source[currentPos++];
                }
                return {NUMBER, lexeme};
            } else {
                std::cerr << "Invalid character: " << c << std::endl;
                return {END_OF_FILE, ""};
            }
    }
}
