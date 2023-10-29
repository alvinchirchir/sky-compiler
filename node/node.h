#ifndef NODE_H
#define NODE_H

#include "../token/token.h"

struct Node {
    TokenType type;
    std::string value;
    Node* left;
    Node* right;

    // Constructor declaration
    Node(TokenType t, const std::string& v, Node* l, Node* r);
};

#endif // NODE_H