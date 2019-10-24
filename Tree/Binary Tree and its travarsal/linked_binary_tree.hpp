#ifndef LINKED_BINARY_TREE_HPP
#define LINKED_BINARY_TREE_HPP

#include <iostream>
#include <memory>

template<typename T>
class node{
public:
	T data ;		// data of the node 
	node *left, *right ;		// pointer to the left child and right child
	node(){
		left = right = nullptr ;		// initializing as nullptr
	}
	node(T val){
		left = right = nullptr ;		// initializing as nullptr
		data = val ;			// assigning values to data
	}
};

template<typename T>
class binary_tree{
public:
	node<T> *root;

	binary_tree(T val);			// constructor
	~binary_tree();			// destructor
	void clear_node(node<T> *cur) ;		// clears a node along with all its childs recursively
	void connect_left(node<T> *parent, node<T> *child) ;		// connect a node in the left of another node.. if there's an existing, deletes that first
	void connect_right(node<T> *parent, node<T> *child) ;		// connect a node in the right of another node.. if there's an existing, deletes that first
};

template<typename T>
binary_tree<T>::binary_tree(T val){
	root = new node<T> (val) ;		// initializing the root 
}

template<typename T>
binary_tree<T>::~binary_tree(){
	clear_node(root) ;			// clears all the nodes recursively
}

template<typename T>
void binary_tree<T>:: clear_node(node<T> *cur){
	if(cur-> left != nullptr)		// if current node has a child in left
		clear_node(cur-> left) ;
	
	if(cur-> right != nullptr)		// if current node has a child in right
		clear_node(cur-> right) ;
	
	delete cur ;		// deleting current node
}

template<typename T>
void binary_tree<T>:: connect_left(node<T> *parent, node<T> *child){
	if(parent->left != nullptr)			// if left link is not empty clears all the nodes in the left recursively
		clear_node(parent-> left) ;
	parent-> left = child ;
}

template<typename T>
void binary_tree<T>:: connect_right(node<T> *parent, node<T> *child){
	if(parent->right != nullptr)		// if right link is not empty clears all the nodes in the right recursively
		clear_node(parent-> right) ;
	parent-> right = child ;
}

#endif