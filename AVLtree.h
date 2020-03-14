#include "BinaryTree.h"

//class implementing the Splay tree
class AVLTree : public BinaryTree{

  //by extending the Binary you have everything you need expect the rank value

public:

  //TODO:
  AVLTree() {}
  ~AVLTree() {}

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
      int left_h = height(node->getLeft());
      int right_h = height(node->getRight());
      if (abs( left_h - right_h ) > 1) {
        if (left_h > right_h) {
          node = node->getLeft();
          int left_h = height(node->getLeft());
          int right_h = height(node->getRight());
          if (left_h > right_h) node = leftLeft( node ); 
          else node = leftRight( node->getRight() );
        }
        if (right_h > left_h){
          node = node->getRight();
          int left_h = height(node->getLeft());
          int right_h = height(node->getRight());
          if (right_h > left_h) node = rightRight( node );
          else node = rightLeft( node->getLeft() );
        }
      }
    }
  }

  void updateParent( Node *p, Node *a, Node *b )
  {
    if (p->getLeft() == a) p->setLeft( b );
    else p->setRight( b );
  }

  //two new functions for performring left rotations
  Node* rightRight( Node *b )
  {
    Node *a = b->getParent();

    a->setRight( b->getLeft() );
    if (b->getLeft() != nullptr) b->getLeft()->setParent( a );
    b->setLeft( a );
    if (a->getParent() == nullptr) setRoot( b );
    else updateParent( a->getParent(), a, b );
    b->setParent( a->getParent() );
    a->setParent( b );
    return b;
  }

  Node* rightLeft( Node *b)
  {
    Node *right = leftLeft( b );
    return rightRight( right );
  }

  //two new functions for performring right rotations
  Node* leftLeft( Node *b )
  {
    Node *a = b->getParent();

    a->setLeft( b->getRight() );
    if (b->getRight() != nullptr) b->getRight()->setParent( a );
    b->setRight( a );
    if (a->getParent() == nullptr) setRoot( b );
    else updateParent( a->getParent(), a, b );
    b->setParent( a->getParent() );
    a->setParent( b );
    return b;
  }
  
  Node* leftRight( Node *b )
  {
    Node *left = rightRight( b );
    return leftLeft( left );
  }
}; 