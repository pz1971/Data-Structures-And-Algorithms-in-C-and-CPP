#ifndef _BST_HPP_
#define _BST_HPP_

#include <iostream>
#include <stack>	// stl

using namespace std ;

// the data container

template<typename T>
class node{
public:
	T data ;
	node *left, *right, *parent ;
	// constructors
	node() ;
	node(T val) ;
};

template<typename T>
node<T>:: node(){
	left = right = parent = nullptr ;
}

template<typename T>
node<T>:: node(T val){
	left = right = parent = nullptr ;
	data = val ;
}
// end of data container

// Binary Search Tree data structure
template<typename T>
class bst{
private:
	size_t _size ;				// number of elements in the tree 
	node<T>* inorder_successor(T val) ;			// returns the address to the inorder successor of the given node

public:
	node<T> *root ;				// address to the root
	bst() ;						// constructor
	~bst() ;					// destructor
	void clear(node<T> *cur);	// clears a sub-tree starting from the node given in parameter... by default - clears all
	size_t size() ;				// returns the size
	bool empty();				// returns if empty or not
	void insert(T elem) ;		// inserts an element in the tree
	void insert(T *array, size_t len) ;		// inserts an array of elements in the tree one by one
	bool search(T elem) ;		// returns true if the element is situated in the tree
	node<T>* find(T elem) ;		// returns the pointer to the element in the tree
	void erase(T elem) ;		// removes the element
	void print(node<T> *cur) ;	// inorder sub-tree
};

template<typename T>
bst<T>:: bst(){
	root = nullptr ;	// initially root is not set
	_size = 0 ;			// size is 0, since no element is here
}

template<typename T>
bst<T>:: ~bst(){
	clear(root) ;
}

template<typename T>
void bst<T>:: clear(node<T> *cur ){
	if(cur == nullptr)	return ;
	
	if(cur->left != nullptr)	// if left sub-tree exists
		clear(cur-> left) ;		// deletes left sub-tree
	if(cur->right != nullptr)	// if right sub-tree exists
		clear(cur->right) ;		// deletes right sub-tree
	if(cur->parent != nullptr){
		if(cur->parent->left == cur)
			cur->parent->left = nullptr ;
		else 
			cur->parent->right = nullptr ;
	}
	delete cur ;				// deletes current node
	_size-- ;					// one node has been removed
}

template<typename T>
size_t bst<T>:: size(){
	return _size ;
}

template<typename T>
bool bst<T>:: empty(){
	return (bool) (_size == 0) ;
}

template<typename T>
void bst<T>:: insert(T elem){
	node<T> *n = new node<T>(elem) ;	// constructs a node with the given value
	if(root == nullptr){
		root = n ;
		_size++ ;
		return ;
	}

	node<T> *cur = root, *par = nullptr ;
	
	while(cur != nullptr){		// travarse and find the right place to insert
		par = cur ;
		if(elem < cur->data)
			cur = cur->left ;
		else 
			cur = cur->right ;
	}

	if(elem < par->data)
		par-> left = n ;		// new node sits in the left
	else 
		par-> right = n ;		//	"  "  "  "	right
	n->parent = par ;			// setting up new nodes parent

	_size++ ;					// one new node inserted
}

template<typename T>
void bst<T>:: insert(T *array, size_t len){
	for(size_t i = 0 ; i < len ; i++){	// insert all the elements in the array one by one
		insert( array[i] ) ;			// calling this overloaded function
	}
}

template<typename T>
bool bst<T>:: search(T elem){
	node<T> *cur = root ;

	while(cur != nullptr){		// just travarse
		if(cur-> data == elem)		// Here I found you :D
			return true ;
		else if(elem < cur-> data)	// you should be in the left :D
			cur = cur-> left ;
		else
			cur = cur-> right ;		// " " " " " " right
	}

	return false ;
}

template<typename T>
node<T>* bst<T>:: find(T elem){
	node<T> *cur = root ;

	while(cur != nullptr){			// just travarse
		if(cur-> data == elem)		// Here I found you :D
			return cur ;
		else if(elem < cur-> data)	// you should be in the left :D
			cur = cur-> left ;
		else
			cur = cur-> right ;		// " " " " " " right
	}

	return cur ;
}

template<typename T>
node<T>* bst<T>:: inorder_successor(T val){
	stack<node<T>*> stk ;
	node<T> *cur = root ;

	bool val_found = false ;

	while(cur != nullptr || !stk.empty()){
		// go as deep as you can :D ***go from left
		while(cur != nullptr){
			stk.push(cur) ;		// pushing current node
			cur = cur-> left ;		// going deeper from left side until I can't :D
		}

		cur = stk.top() ;	// deepest node unvisited is in the top of the stack
		stk.pop() ;			// popping it out
		
		if(val_found == true)	// the node has already been found.. so this one(popped exacty after the val) should be the inorder successor
			break ;		// breaks and return action occurs
		if(cur-> data == val)
			val_found = true ;

		cur = cur-> right ;	// now I can go right :D
	}
	return cur ;
}

template<typename T>
void bst<T>:: erase(T elem){
	node<T> *n = find(elem) ;
	if(n == nullptr)	// not in the tree
		return ;
	_size-- ;

	node<T> *par ;
	if(n != root)
		par = n-> parent ;
	else par = nullptr ;


	if(n-> left == nullptr && n-> right == nullptr){	// no child
		if(par != nullptr){
			if(par->left == n)
				par-> left = nullptr ;
			else 
				par-> right = nullptr ;
		}
		delete n ;
	}

	else if(n-> left != nullptr && n-> right == nullptr){	// one child (left)
		if(par == nullptr){
			root = n-> left ;
			delete n ;
		}
		else{
			if(par->left == n){
				par-> left = n-> left ;
				n->left->parent = par ;
			}
			else{
				par-> right = n-> left ;
				n->left->parent = par ;
			}
			delete n ;
		}
	}

	
	else if(n-> left == nullptr && n-> right != nullptr){	// one child (right)
		if(par == nullptr){
			root = n-> right ;
			delete n ;
		}
		else{
			if(par->left == n){
				par-> left = n-> right ;
				n->right->parent = par ;
			}
			else{
				par-> right = n-> right ;
				n->right->parent = par ;
			}
			delete n ;
		}
	}

	else{	// two child
		// find inorder successor node
		node<T>* s = inorder_successor(elem) ;
		//	swap it with n
		n->data = s->data ;
		// delete n
		if(s->parent->left == s)
			s->parent->left = nullptr ;
		else 
			s->parent->right = nullptr ;
		delete s ;	// why deleting s? cause, s is the new n after swaping... we didn't swap their address..right?
	}
}

template<typename T>
void bst<T>:: print(node<T>* cur ){
	if(cur == nullptr)	return ;
	
	print(cur->left) ;
	std:: cout << cur-> data << " " ;
	print(cur-> right);
}

#endif