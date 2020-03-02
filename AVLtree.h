#include "BinaryTree.h"

//class implementing the Splay tree
class AVLTree : public BinaryTree{

  //by extending the Binary you have everything you need expect the rank value

public:

  //TODO:
  Node* Search( int key )
  {
    return BinaryTree::Search( key );
  }

  //a new function for inserting a node into the tree
    //you can start by callling the insert function from the binary tree
    //additionally you have to perform rotations if necessary
  void Insert( int key )
  {
    Node* last = BinaryTree::Insert( key );
    rebalanceAVL( last );
  }

  //a new function for deleting a node into the tree
    //you can start by callling the delete function from the binary tree
    //additionally you have to perform rotations if necessary
  void Delete( int key )
  {
    Node* last = BinaryTree::Delete( key );
    rebalanceAVL( last );
  }

  //helper function
  int height( Node *node )
  {
    if (node == nullptr) return 0;

    int h = 1;    
    int lh = height( node->getLeft() );
    int rh = height( node->getRight() );
    h += max(lh, rh);

    return h;
  }

  void rebalanceAVL( Node *node )
  {
    while (node != BinaryTree::getRoot()) {
      node = node->getParent();
      int left_h =height(node->getLeft());
      int right_h =height(node->getRight());
      if (abs( left_h - right_h ) > 1) {
        if (left_h > right_h) rightSingle(node);
        else if (left_h < right_h) leftSingle(node);

      }
    }
  }

  //two new functions for performring left rotations
  void leftSingle( Node *b )
  {
    Node *a = b->getRight();
    Node *c = b->getLeft();
    int b_key = b->getKey();

    b->setKey( a->getKey() );
    b->setRight( a->getRight() );
    b->setLeft( a );

    a->setKey( b_key );
    a->getRight()->setParent( b );
    a->setRight( a->getLeft() );
    a->setLeft( c );

    c->setParent( a );
  }
  
  void leftDouble()
  {

  }

  //two new functions for performring right rotations
  void rightSingle( Node *b )
  {
    Node *a = b->getLeft();
    Node *c = b->getRight();
    int b_key = b->getKey();

    b->setKey( a->getKey() );
    b->setLeft( a->getLeft() );
    b->setRight( a );

    a->setKey( b_key );
    a->getLeft()->setParent( b );
    a->setLeft( a->getRight() );
    a->setRight( c );

    c->setParent( a );
  }

  void rightDouble()
  {
    
  }


};
