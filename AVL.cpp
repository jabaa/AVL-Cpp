//
// Created by Thomas Sablik on 02.07.2015.
//

#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include "AVL.h"

std::string toString(int x, int i){
    std::string str(std::to_string(x));
    return spaces(std::ceil(std::max(static_cast<int>(i-str.length()),0)/2)) + str + spaces(std::floor(std::max(static_cast<int>(i-str.length()),0)/2));
}

std::string spaces(int x){
    std::string str;
    for(int i = 0; i < x; i++){
        str.append(" ");
    }
    return str;
}

Node::Node(TYPE key_){
    lChild = 0;
    rChild = 0;
    height = 0;
    key = key_;
}

AVL::AVL(){
    root = 0;
}

AVL::AVL(TYPE key){
    root = new Node(key);
}

std::string AVL::toString(){
    std::string nodesString("");
    int height = -1;
    int width;
    int nodeWidth;
    if(root){
        nodeWidth = static_cast<int>(std::floor(std::log10(getMax())) + 1);
    }else{
        return nodesString;
    }

    std::vector<Node*> nodes;
    if(root){
        nodes.push_back(root);
        height = root->height;
        width = static_cast<int>((pow(2, height) * 2) - 1);
        nodesString.append(spaces(nodeWidth * ((width - 1) / 2)) + ::toString(root->key, nodeWidth) + spaces(nodeWidth * ((width - 1) / 2)) + "\n");
    }
    std::vector<Node*> newNodes;
    for(int i = 1; i <= height; i++){
        newNodes.clear();
        for(std::vector<Node*>::iterator j = nodes.begin(); j != nodes.end(); j++){
            if(!(*j)){
                newNodes.push_back(0);
                nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                nodesString.append(spaces(nodeWidth));
                nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                nodesString.append(spaces(nodeWidth));
                newNodes.push_back(0);
                nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                nodesString.append(spaces(nodeWidth));
                nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
            }else{
                if((*j)->lChild){
                    newNodes.push_back((*j)->lChild);
                    nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                    nodesString.append(::toString((*j)->lChild->key, nodeWidth));
                    nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                }else{
                    newNodes.push_back(0);
                    nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                    nodesString.append(spaces(nodeWidth));
                    nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                }
                nodesString.append(spaces(nodeWidth));
                if((*j)->rChild){
                    newNodes.push_back((*j)->rChild);
                    nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                    nodesString.append(::toString((*j)->rChild->key, nodeWidth));
                    nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                }else{
                    newNodes.push_back(0);
                    nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                    nodesString.append(spaces(nodeWidth));
                    nodesString.append(spaces(nodeWidth * (std::pow(2,(height - i)) - 1)));
                }
            }
            nodesString.append(spaces(nodeWidth));
        }
        nodesString = nodesString.substr(0,nodesString.length()-nodeWidth) + "\n";
        nodes = newNodes;
    }
    return nodesString;
}

void AVL::insert(TYPE key) {
    Node *node = new Node(key);
    Node *currNode = 0;
    bool isInserted = 0;
    std::vector<Node*> editedNodes;
    if(root){
        currNode = root;
        editedNodes.push_back(currNode);
    }else{
        root = node;
        isInserted = 1;
    }

    while(!isInserted){
        if(node->key >= currNode->key){
            if(currNode->rChild) {
                currNode = currNode->rChild;
                editedNodes.push_back(currNode);
            }else{
                currNode->rChild = node;
                isInserted = 1;
            }
        }else{
            if(currNode->lChild) {
                currNode = currNode->lChild;
                editedNodes.push_back(currNode);
            }else{
                currNode->lChild = node;
                isInserted = 1;
            }
        }
    }

    for(std::vector<Node*>::reverse_iterator i = editedNodes.rbegin(); i != editedNodes.rend(); i++){
        (*i)->height = std::max(getHeight((*i)->lChild), getHeight((*i)->rChild)) + 1;
    }
}

TYPE AVL::getMax(){
    Node *currNode;
    if(!root){
        return 0;
    }else{
        currNode = root;
        while(currNode->rChild){
            currNode = currNode->rChild;
        }
        return currNode->key;
    }
}

int AVL::getHeight(Node *node) {
    if(!node){
        return -1;
    }else{
        return node->height;
    }
}