//
// Created by Thomas Sablik on 02.07.2015.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H

#define TYPE int
#include <string>

std::string spaces(int);
std::string toString(TYPE, int);

class Node{
public:
    Node *lChild;
    Node *rChild;
    int height;
    TYPE key;
    Node(TYPE);
};

class AVL {
public:
    Node *root;
    AVL();
    AVL(TYPE);

    std::string toString();
    void insert(TYPE);
    TYPE getMax();

    int getHeight(Node*);
};


#endif //AVL_AVL_H
