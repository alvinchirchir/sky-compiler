#include "parser.h"
#include "../lexer/lexer.h"
#include "../node/node.h"
#include "../token/token.h"
#include <iostream>

Parser::Parser(Lexer& lexer) : lexer(lexer) {
    currentToken = lexer.getNextToken();
}

Node* Parser::parseAssignment() {
    if (currentToken.type == VARIABLE) {
        std::string variableName = currentToken.lexeme;
        currentToken = lexer.getNextToken();

        if (currentToken.type == ASSIGN) {
            currentToken = lexer.getNextToken();
            if (currentToken.type == NUMBER) {
                std::string numberValue = currentToken.lexeme;
                currentToken = lexer.getNextToken();

                if (currentToken.type == SEMICOLON) {
                    Node* assignmentNode = new Node(ASSIGN, "", nullptr, nullptr);
                    Node* variableNode = new Node(VARIABLE, variableName, nullptr, nullptr);
                    Node* numberNode = new Node(NUMBER, numberValue, nullptr, nullptr);

                    assignmentNode->left = variableNode;
                    assignmentNode->right = numberNode;

                    return assignmentNode;
                }
            }
        }
    }

    std::cerr << "Invalid assignment statement." << std::endl;
    exit(1); // Exit with an error
}

