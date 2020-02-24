#include <stdlib.h>
#include <iostream>

using namespace std;

class Node
{
  //Each node should have
  //- pointer to the parent node
  //- pointer to left child
  //- pointer to right child
  //- int for storing the key value
  Node* parent;
  Node* left;
  Node* right;
  int key;

  public:
    //constructor
    //remember to always inizialize pointers to NULL
    //getter and setter for other nodes and value
    Node(): parent( nullptr ), left(nullptr), right(nullptr), key(0) {}

    Node* getParent() { return parent; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }
    int getKey() { return key; }

    void setParent( Node* parent ) { this->parent = parent; }
    void setLeft( Node* left ) { this->left = left; }
    void setRight( Node* right ) { this->right = right; }
    void setKey( int key ) { this->key = key; }
};

class BinaryTree
{
  protected:
    //A tree should store its root only.
    Node* root;

  private:
    void inOrder( Node* node )
    {
      if (root == nullptr) {
        cout << "empty tree" << endl;
        return;
      }
      else {
        if (node->getLeft() != nullptr) {
          inOrder(node->getLeft());
        }
        cout << node->getKey() << " ";

        if (node->getRight() != nullptr) {
          inOrder(node->getRight());
        }
      }
    }

    Node* createNode( int key )
    {
      Node* temp = new Node();
      temp->setKey( key );
      return temp;
    }

    Node* searchNode( int key, Node* node )
    {
      return nullptr;
    }

    Node* insertNode( int key, Node* node )
    {
      Node* last;
      if (root == nullptr) {
        setRoot(key);
        last = root;
      }

      else if (key <= node->getKey()) {
        if (node->getLeft() != nullptr ) insertNode( key, node->getLeft() );
        else {
          node->setLeft( createNode(key) );
          
        }
        last = node->getLeft();
      }

      else {
        if (node->getRight() != nullptr ) insertNode( key, node->getRight() );
        else {
          node->setRight( createNode(key) );

        }
        last = node->getRight();
      }

      return last;
    }

    Node* deleteNode( int key, Node* node )
    {
      return nullptr;
    }


  public:
    //functions required
    //- constructor
    //- getter setter root
    //- a function for printing the inorder visit of the tree
    //- a function for searching a value in the tree.
    //- a function for inserting a new value in the tree
    //- a function for deleting a value from the tree
    BinaryTree(): root(nullptr) {}
    
    Node* getRoot() { return root; }

    void setRoot( int key )
    {
      root = new Node();
      root->setKey(key);
    }

    void printInOrder() { inOrder(root); }
    Node* Search( int key ) { return nullptr; }
    Node* Insert( int key ) { return insertNode( key, getRoot() ); }
    Node* Delete( int key ) { return nullptr; }
};
