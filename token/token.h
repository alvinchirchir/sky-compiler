#ifndef TOKEN_H
#define TOKEN_H
#include <string>
// Define token types
enum TokenType {
    VARIABLE,
    ASSIGN,
    NUMBER,
    SEMICOLON,
    END_OF_FILE
};

// Token structure
struct Token {
    TokenType type;
    std::string lexeme;
};

#endif // TOKEN_H