#include "AVLtree.h"
#include "Timer.h"

int main(int argc, char* argv[])
{
    BinaryTree binTree;

    binTree.Insert(10);
    binTree.Insert(12);
    binTree.Insert(8);
    binTree.Insert(11);
    binTree.Insert(13);
    binTree.Insert(7);
    
    binTree.printInOrder();
    cout << endl;

    return 0;
}