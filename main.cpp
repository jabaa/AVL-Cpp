#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
    AVL avl;
    avl.insert(67);
    avl.insert(58);
    avl.insert(19);
    avl.insert(24);
    avl.insert(57);
    avl.insert(78);
    avl.insert(74);
    avl.insert(72);
    avl.insert(82);
    avl.insert(87);
    std::cout << avl.toString() << std::endl;
    return 0;
}