#include <iostream>
#include <string>
#include "lexer/lexer.h"
#include "parser/parser.h"



void printAST(Node* node, int indent = 0) {
    if (node) {
        for (int i = 0; i < indent; i++) {
            std::cout << "  ";
        }
        std::cout << "Type: " << node->type << ", Value: " << node->value << std::endl;
        printAST(node->left, indent + 1);
        printAST(node->right, indent + 1);
    }
}

int main() {
    std::string input = "x=11;x=11;";
    Lexer lexer(input);
    Parser parser(lexer);


    Node* ast = parser.parseAssignment();

    if (ast) {
        std::cout << "Abstract Syntax Tree:" << std::endl;
        printAST(ast);
    }

    return 0;
}