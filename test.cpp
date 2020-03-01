#include "AVLtree.h"
#include "Timer.h"

int main(int argc, char* argv[])
{
    BinaryTree binTree;

    binTree.Insert(10);
    binTree.Insert(5);
    binTree.Insert(3);
    binTree.Insert(8);
    binTree.Insert(1);
    binTree.Insert(4);
    binTree.Insert(6);
    binTree.Insert(9);
    binTree.Insert(15);
    binTree.Insert(12);
    binTree.Insert(17);
    binTree.Insert(13);
    binTree.Insert(16);
    binTree.Insert(18);
    binTree.Insert(8);
    binTree.Insert(8);

    binTree.printInOrder();
    cout << endl;

    // for (int i = 0; i < 16; i++) {
    //     if (binTree.Search(i) == nullptr) cout << "nothing here chief" << endl;
    //     else cout << binTree.Search(i)->getKey() << endl;;
    // }

    cout << endl << "******" << endl;
    // if (binTree.Search(3)->getRight() == nullptr) cout << "NULLLLL" << endl;
    // else cout << binTree.Search(3)->getKey() << endl;
    // binTree.Delete(10);
    binTree.Delete(10);
    // binTree.Delete(3);
    // binTree.Delete(4);
    // binTree.Delete(8);
    // binTree.Delete(6);
    // binTree.Delete(3);
    // binTree.Delete();
    // binTree.Delete(13);
    // binTree.Delete(13);
    // binTree.Delete(13);
    // if (binTree.Delete(8) == nullptr) cout << "key's not here man" << endl;
    // else cout << binTree.Delete(100)->getKey() << endl;
    binTree.printInOrder();
    
    return 0;
}