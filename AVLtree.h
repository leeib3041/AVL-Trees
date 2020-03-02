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
    // cout << "last: " << last->getKey() << endl;
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
          if (right_h < left_h) rightSingle( node ); 
          else rightDouble( node );
        }
        if (left_h < right_h){
          node = node->getRight();
          int left_h = height(node->getLeft());
          int right_h = height(node->getRight());
          if (right_h > left_h) leftSingle( node );
          else leftDouble( node );
        }
      }
    }

  }

  //two new functions for performring left rotations
  Node* leftSingle( Node *b )
  {
    Node *a = b->getRight();
    Node *temp = a->getLeft();
    
    b->setRight( a->getLeft() );
    a->setLeft( b );
    a->setParent( b->getParent() );
    b->setParent( a );
    if (temp != nullptr) temp->setParent( b );
    if (a->getParent() == nullptr) BinaryTree::setRoot();

    return a;
  }
  
  void leftDouble( Node *b )
  {
    Node *temp = rightSingle( b );
    leftSingle( temp->getParent() );
  }

  //two new functions for performring right rotations
  Node* rightSingle( Node *b )
  {
    Node *a = b->getLeft();
    Node *temp = a->getRight();
    
    b->setLeft( a->getRight() );
    a->setRight( b );
    a->setParent( b->getParent() );
    b->setParent( a );
    if (temp != nullptr) temp->setParent( b );
    if (a->getParent() == nullptr) BinaryTree::setRoot();

    return a;
  }

  void rightDouble( Node *b)
  {
    Node *temp = leftSingle( b );
    rightSingle( temp->getParent() );
  }
};
