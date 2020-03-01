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
    Node(): parent( nullptr ), left( nullptr ), right( nullptr ), key(0) {}
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
        cout << "Empty tree" << endl;
        return;
      }
      else {
        if (node->getLeft() != nullptr) {
          inOrder(node->getLeft());
        }
        int parent;
        if (node->getParent() != nullptr) parent = node->getParent()->getKey();
        else parent = 999;
        cout << "key: " << node->getKey() << "  parent:" <<  parent << endl;

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

    //Helper function
    bool hasChild( Node *node )
    {
      if (node == nullptr) return false;
      if (node->getLeft() == nullptr && node->getRight() == nullptr) return false;
      return true;
    }

    Node* TreeSearch( int key, Node *node )
    {
      //return null on empty tree or tree has only root node
      if (root == nullptr) return root;
      while (hasChild( node )) {
        if (key == node->getKey()) return node;
        else if (key <= node->getKey() && node->getLeft() != nullptr) node = node->getLeft();
        else if (key > node->getKey() && node->getRight() != nullptr) node = node->getRight();
        else return node;
      }
      return node;
    }

    bool hasDupl( int key, Node* node )
    {
      if (key > node->getKey()) return false;
      if (node->getLeft() == nullptr) return false;
      return true;
    }

    Node* TreeInsert( int key, Node *node )
    {
      if (root == nullptr) {
        setRoot(key);
        return root;
      }

      Node* curr = TreeSearch( key, node );
      //handle duplicate key's
      while (hasDupl( key, curr )) curr = TreeSearch( key, curr->getLeft() );
      if (key <= curr->getKey()) {
        curr->setLeft( createNode(key, curr) );
        return curr->getLeft();
      }
      else {
        curr->setRight( createNode(key, curr) );
        return curr->getRight();
      }
    }

    //helper function
    Node* updateParent( Node *child, Node *parent, Node *node )
    {
      if (child != nullptr) child->setParent( parent );
      if (parent == nullptr) root = child;
      else {
        if (parent->getLeft() == node) parent->setLeft( child );
        else parent->setRight( child );
      }

      return parent;
    }

    Node* TreeDelete( int key, Node *node )
    {
      Node *curr = TreeSearch( key, node );
      if (curr->getKey() != key) return node;
      if (curr != nullptr) {
        Node *parent = nullptr, *child = nullptr;
        //no children
        if (curr->getLeft() == nullptr && curr->getRight() == nullptr) parent = updateParent( nullptr, curr->getParent(), curr );
        //one child - right
        else if (curr->getLeft() == nullptr) parent = updateParent( curr->getRight(), curr->getParent(), curr );
        //one child - left
        else if (curr->getRight() == nullptr) parent = updateParent( curr->getLeft(), curr->getParent(), curr );
        //full children
        else {
          child = curr->getRight();
          while (child->getLeft() != nullptr) {
            child = child->getLeft();
          }
          curr->setKey( child->getKey() );
          parent = updateParent( child->getRight(), child->getParent(), child );
          curr = child;
        }
        delete curr;
        return parent;
      }
      else cout << "Key " << key << " not found in Tree!" << endl;
      return node;
    }

    void TreeDestroy( Node *curr )
    {
      if (curr != nullptr) {
        TreeDestroy( curr->getLeft() );
        TreeDestroy( curr->getRight() );
        delete curr;
      }
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
    ~BinaryTree() { TreeDestroy(root); }

    Node* getRoot() { return root; }
    void setRoot( int key )
    {
      root = new Node();
      root->setKey(key);
    }

    void printInOrder() { inOrder(root); }
    Node* Search( int key ) { return TreeSearch( key, root ); }
    Node* Insert( int key ) { return TreeInsert( key, root ); }
    Node* Delete( int key ) { return TreeDelete( key, root ); }
};
