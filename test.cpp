#include "AVLtree.h"
#include "Timer.h"

int main(int argc, char* argv[])
{
    BinaryTree binTree;
    // binTree.Insert(1);
    // binTree.Delete(1);
    // binTree.printInOrder();
    //
    // binTree.Insert(10);
    // binTree.Insert(10);
    // binTree.Insert(10);
    // binTree.Insert(3);
    // binTree.Insert(8);
    // binTree.Insert(1);
    // binTree.Insert(4);
    // binTree.Insert(6);
    // binTree.Insert(9);
    // binTree.Insert(15);
    // binTree.Insert(12);
    // binTree.Insert(17);
    // binTree.Insert(13);
    // binTree.Insert(16);
    // binTree.Insert(18);
    // binTree.Insert(8);
    // binTree.Insert(8);
    
    // binTree.printInOrder();
    // cout << endl;
    // for (int i = 0; i < 20; i++) {
    //     cout << binTree.Search(i)->getKey() << endl;;
    // }
    //
    // cout << endl << "******" << endl;
    //
    // binTree.Delete(10);
    // binTree.Delete(12);
    // binTree.Delete(3);
    // binTree.Delete(4);
    // binTree.Delete(8);
    // binTree.Delete(16);
    // binTree.Delete(3);
    // binTree.Delete(10);
    // binTree.Delete(13);
    // binTree.Delete(13);
    // binTree.Delete(13);
    // binTree.printInOrder();

    AVLTree avl;
    
    avl.Insert(10);
    avl.Insert(5);
    avl.Insert(15);
    avl.Insert(3);
    avl.Insert(7);
    avl.Insert(1);
    avl.Insert(10);
    avl.Insert(2);
    avl.Insert(55);
    avl.Insert(4);
    avl.Insert(7);
    avl.Insert(5);
    avl.Insert(15);
    avl.Insert(13);
    avl.Insert(14);
    avl.Insert(18);
    avl.Insert(1);
    avl.Insert(66);
    avl.printInOrder();
    cout << endl;

    avl.Delete(15);
    avl.printInOrder();
    

    return 0;
}
