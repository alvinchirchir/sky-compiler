#include "node.h"

// Constructor implementation
Node::Node(TokenType t, const std::string& v, Node* l, Node* r)
    : type(t), value(v), left(l), right(r) {
    //  Add constructor logic here
}
