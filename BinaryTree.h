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
  Node *parent;
  Node *left;
  Node *right;
  int key;

  public:
    //constructor
    //remember to always inizialize pointers to NULL
    //getter and setter for other nodes and value
    Node(): parent( nullptr ), left(nullptr), right(nullptr), key(0) {}
    ~Node() {}

    Node* getParent() { return parent; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }
    int getKey() { return key; }

    void setParent( Node *parent ) { this->parent = parent; }
    void setLeft( Node *left ) { this->left = left; }
    void setRight( Node *right ) { this->right = right; }
    void setKey( int key ) { this->key = key; }
};

class BinaryTree
{
  protected:
    //A tree should store its root only.
    Node *root;

  private:
    //In-Order print of tree
    void inOrder( Node *node )
    {
      if (root == nullptr) {
        cout << "empty tree" << endl;
        return;
      }
      else {
        if (node->getLeft() != nullptr) {
          inOrder(node->getLeft());
        }
        int parent;
        if (node->getParent() != nullptr) parent = node->getParent()->getKey();
        else parent = 999;
        cout << node->getKey() << " " <<  parent << endl;

        if (node->getRight() != nullptr) {
          inOrder(node->getRight());
        }
      }
    }

    //Helper function
    Node* createNode( int key, Node *parent )
    {
      Node *temp = new Node();
      temp->setKey( key );
      temp->setParent( parent );
      return temp;
    }

    Node* TreeSearch( int key, Node *node )
    {
      if (root == nullptr) return root; // return NULL when searching empty tree
      else if (node == nullptr) return node;
      else {
        if (key == node->getKey()) { return node; }
        else if (key <= node->getKey()) return TreeSearch( key, node->getLeft() );
        else return TreeSearch( key, node->getRight() );
      }
    }

    Node* TreeInsert( int key, Node *node )
    {
      if (root == nullptr) {
        setRoot(key);
        return root;
      }
      else if (key <= node->getKey()) {
        if (node->getLeft() != nullptr ) return TreeInsert( key, node->getLeft() );
        else {
          node->setLeft( createNode(key, node) );
          return node->getLeft();
        }
      }
      else {
        if (node->getRight() != nullptr ) return TreeInsert( key, node->getRight() );
        else {
          node->setRight( createNode(key, node) );
          return node->getRight();
        }
      }
    }

    //helper function
    Node* onlyChild( Node *child, Node *parent, Node *node )
    {
      child->setParent( parent );
      if (parent == nullptr) {
        delete (node);
        return parent;
      }
      if (parent->getLeft() == node) parent->setLeft( child );
      else parent->setRight( child );
      int key = node->getKey();
      delete node;
      return parent;
    }

    Node* TreeDelete( int key, Node *node )
    {
      Node *curr = TreeSearch( key, node );
      if (curr != nullptr) {
        Node *parent, *child;
        if (curr->getLeft() == nullptr && curr->getRight() == nullptr) {
          parent = curr->getParent();
          delete curr;
          cout << curr->getKey() << endl;
          return parent;
        }
        else if (curr->getLeft() == nullptr) {
          return onlyChild( curr->getRight(), curr->getParent(), curr );
        }
        else if (curr->getRight() == nullptr) {
          return onlyChild( curr->getLeft(), curr->getParent(), curr );
        }
        else {
          child = curr->getRight();
          while (child->getLeft() != nullptr) {
            child = curr->getLeft();
          }
          curr->setKey( child->getKey() );
          if (child->getRight() != nullptr) return onlyChild( child->getRight(), child->getParent(), child );
          else {
            parent = child->getParent();
            delete child;
            return parent;
          }
        }
      }
      else return node;
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
    ~BinaryTree() {}

    Node* getRoot() { return root; }
    void setRoot( int key )
    {
      root = new Node();
      root->setKey(key);
    }

    void printInOrder() { inOrder(root); }
    Node* Search( int key ) { return TreeSearch( key, getRoot() ); }
    Node* Insert( int key ) { return TreeInsert( key, getRoot() ); }
    Node* Delete( int key ) { return TreeDelete( key, getRoot() ); }
};
