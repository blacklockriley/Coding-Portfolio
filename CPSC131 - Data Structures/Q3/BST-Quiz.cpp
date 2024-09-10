/*******************************************************************************
** CPSC 131: Part 4 - Associative Containers
**           Binary Search Tree Quiz
**
** Implement the Binary Search Tree code asked for in each question (TO-DO) below.
** The tree shall have no duplicate keys
**
** While the solutions to the questions below are highly inspired by the implementation
** examples presented in class, they will not be identical.  Read the questions carefully.
*******************************************************************************/


#include <utility>
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>




template<typename Key, typename Value>
struct BST
{
  using KeyValue_Pair = std::pair<Key const, Value>;

  struct Node
  {
    Node() = default;
    Node( KeyValue_Pair const & pair ) : _pair{ pair } {}

    KeyValue_Pair _pair = { Key{}, Value{} };

    Node * _left   = nullptr;
    Node * _right  = nullptr;
    Node * _parent = nullptr;
  };

  Node *      _root = nullptr;
  std::size_t _size = 0;









  /*****************************************************************************
  ** Implement the BST's find function
  **   1)  find takes a key as its only argument and returns a pointer to the node containing that key
  **   2)  Write a recursive solution (not an iterative solution  Hint:  no while or for loops)
  **       o)  Write both the "public" and "private helper" functions
  **       o)  Clearly identify the Base Case, Visit, and Recurse steps  Hint:  write comments for each
  **           step before writing code
  **       o)  You may only compare the keys once
  *****************************************************************************/
  Node * find( Key const & key )
  {
    ///////////////////////// TO-DO (1) //////////////////////////////
    return find( key, _root );    // call the private helper function
    /////////////////////// END-TO-DO (1) ////////////////////////////
  }


  Node * find( Key const & key, Node * current )
  {
    ///////////////////////// TO-DO (2) //////////////////////////////
    if( current == nullptr ) return nullptr;                                      // Base Case

    auto comp = std::compare_weak_order_fallback( key, current->_pair.first );    // Compare the keys only once
    if( comp == 0 ) return current;                                               // Visit
    if( comp < 0 ) return find( key, current->_left );                            // Recurse

    return find( key, current->_right );                                          // Recurse
    /////////////////////// END-TO-DO (2) ////////////////////////////
  }



  /*****************************************************************************
  ** Implement the BST's insert function
  **   1)  Insert takes a key-value pair as its only argument and returns a pointer to the
  **       node containing that key
  **   2)  Write an iterative solution (not a recursive solution)
  **   3)  You may only compare the keys once
  *****************************************************************************/
  Node * insert( KeyValue_Pair const & pair )
  {
    ///////////////////////// TO-DO (3) //////////////////////////////
    Node *  current = _root;      // Start at the root
    Node *  parent  = nullptr;    // Parent of the current node
    Node ** child   = &_root;     // Pointer to the child of the parent

    while( current != nullptr )    // Traverse the tree
    {
      auto comp = std::compare_weak_order_fallback( pair.first, current->_pair.first );    // Compare the keys only once

      if( comp == 0 ) return current;    // If the key already exists, return the node

      parent = current;                                                    // Update the parent
      if( comp < 0 ) child = &current->_left, current = current->_left;    // Traverse the left subtree
      else                                                                 // comp > 0
        child = &current->_right, current = current->_right;               // Traverse the right subtree
    }

    Node * newNode   = new Node( pair );    // Create a new node
    newNode->_parent = parent;              // Set the parent of the new node
    *child           = newNode;             // Set the child of the parent to the new node
    ++_size;                                // Increment the size of the tree

    return newNode;    // Return the new node
    /////////////////////// END-TO-DO (3) ////////////////////////////
  }



  /*****************************************************************************
  ** Implement the BST's erase function
  **   1)  Erase takes a key as its only argument and returns nothing
  **   2)  Write an iterative solution (not a recursive solution)
  **   3)  Simplification:: Assume the node you are erasing does NOT have two children.  Do not write code
  **       to erase a node with two children.
  *****************************************************************************/
  void erase( Key const & key )
  {
    ///////////////////////// TO-DO (4) //////////////////////////////
    Node * position = find( key );    // Find the node with the given key

    if( position != nullptr )    // If the node exists
    {
      Node *  position_ptr = position;    // Get the pointer to the node

      Node ** parent       = position_ptr->_parent == nullptr             ? &_root                             // If the node is the root
                           : position_ptr->_parent->_left == position_ptr ? &position_ptr->_parent->_left      // If the node is the left child
                                                                          : &position_ptr->_parent->_right;    // If the node is the right child

      Node *  child        = position_ptr->_left ? position_ptr->_left : position_ptr->_right;    // Get the child of the node

      *parent              = child;                          // Set the parent of the node to the child
      if( child ) child->_parent = position_ptr->_parent;    // Set the parent of the child to the parent of the node

      delete position_ptr;    // Delete the node
      --_size;                // Decrement the size of the tree
    }
      /////////////////////// END-TO-DO (4) ////////////////////////////
    }



  /*****************************************************************************
  ** Implement the BST's index operator function
  **   1)  operator[] takes a key as its only argument and returns a reference to the
  **       value associated with that key
  **   2)  If the key does not already exist, insert it
  *****************************************************************************/
  Value & operator[]( Key const & key )
  {
    ///////////////////////// TO-DO (5) //////////////////////////////
    Node * node = find( key );    // Find the node with the given key
    if( node == nullptr )         // If the node does not exist
    {
      node = insert( { key, Value{} } );    // Insert the key-value pair
    }
    return node->_pair.second;    // Return the value associated with the key
    /////////////////////// END-TO-DO (5) ////////////////////////////
  }



  /*****************************************************************************
  ** Implement the BST's clear function
  **   1)  Clear takes a pointer-to-Node as its only argument and returns nothing
  **   2)  Write a recursive solution (not an iterative solution  Hint:  no while or for loops)
  **       o)  Write the "private helper" function only (the "public" function is provided)
  **       o)  Clearly identify the Base Case, Visit, and Recurse steps  Hint:  write comments for each
  **           step before writing code
  *****************************************************************************/
  void clear() noexcept
  {
    clear( _root );
    _root = nullptr;
    _size = 0;
  }


  void clear( Node * current ) noexcept
  {
    ///////////////////////// TO-DO (6) //////////////////////////////
    if( current == nullptr ) return;    // Base Case
    clear( current->_left );             // Recurse
    clear( current->_right );            // Recurse
    delete current;                      // Visit
    --_size;                              // Decrement the size of the tree
    /////////////////////// END-TO-DO (6) ////////////////////////////
  }









  void print()
  {
    auto count = 0uz;
    print( _root, count );
  }

  void print( Node * current, std::size_t & count )  // in-order traversal
  {
    if( current == nullptr ) return;
    print( current->_left, count );

    auto && [key, value] = current->_pair;
    std::cout << std::setw(3) << ++count << ":  {" << key << ", " << value << "}\n";

    print( current->_right, count );
  }


  ~BST() noexcept
  { clear(); }
};






int main()
{
  BST<unsigned int, std::string> myTree;

  std::cout << "Test Case 1:\n";                     //          50         //
  myTree[50] = "indeed";                             //        /   \        //
  myTree.insert( { 40, "Structures" } );             //       40    60      //
  myTree.insert( { 60, "very" } );                   //      / \   / \      //
  myTree.insert( { 30, "Lego" } );                   //     30 45 55  70    //
  myTree.insert( { 45, "are" } );
  myTree[55] = "truly";
  myTree[70] = "entertaining";
  myTree.print();
  std::cout << "------------------------------\n";



  std::cout << "\n\nTest Case 2:\n";                 //          50         //
  myTree.erase( 70 );                                //        /   \        //
  myTree[30] = "Data";                               //       40    55      //
  myTree.erase( 60 );                                //      / \     \      //
  myTree.insert( { 75, "awesome" } );                //     30 45     75    //
  myTree.insert( { 50, "never" } );
  myTree.print();
  std::cout << "------------------------------\n";



  std::cout << "\n\nTest Case 3:\n";
  BST<char, int> anotherTree;
  anotherTree.find ('A');
  anotherTree.erase('B');
  std::cout << "myTree._size:       " << myTree     ._size << '\n'
            << "anotherTree._size:  " << anotherTree._size << '\n';

  auto n1 = anotherTree.insert({ 'C',0 });
  auto n2 = anotherTree.insert({ 'D',0 });
  auto n3 = anotherTree.insert({ 'B',0 });
  auto n4 = anotherTree.insert({ 'C',0 });
  auto n5 = anotherTree.insert({ 'D',0 });
  auto n6 = anotherTree.insert({ 'B',0 });
  std::cout << std::boolalpha
            << "Node 'B' found:  " << (n3 == n6 && n6 == anotherTree.find('B')) << '\n'
            << "Node 'C' found:  " << (n1 == n4 && n4 == anotherTree.find('C')) << '\n'
            << "Node 'D' found:  " << (n2 == n5 && n5 == anotherTree.find('D')) << '\n';
    std::cout << "------------------------------\n";
}
