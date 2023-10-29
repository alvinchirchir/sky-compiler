#ifndef PARSER_H
#define PARSER_H

#include "../lexer/lexer.h"
#include "../node/node.h"
#include "../token/token.h"

class Parser {
public:
    Parser(Lexer& lexer);
    Node* parseAssignment();

private:
    Lexer& lexer;
    Token currentToken;
};

#endif // PARSER_H
