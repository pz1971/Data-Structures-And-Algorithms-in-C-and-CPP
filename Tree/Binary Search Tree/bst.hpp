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
	left = right = nullptr ;
}

template<typename T>
node<T>:: node(T val){
	left = right = nullptr ;
	data = val ;
}
// end of data container

// Binary Search Tree data structure
template<typename T>
class bst{
private:
	size_t _size ;							// number of elements in the tree 
	node<T>* inorder_successor(T val) ;		// returns the address to the inorder successor of the given node
	void clear(node<T> *cur);				// clears the sub-tree rooted from parameter

public:
	node<T> *root ;							// address to the root
	bst() ;									// constructor
	~bst() ;								// destructor
	void clear();							// clears the full tree
	size_t size() ;							// returns the size
	bool empty();							// returns if empty or not
	void insert(T elem) ;					// inserts an element in the tree
	void insert(T *array, size_t len) ;		// inserts an array of elements in the tree one by one
	bool search(T elem) ;					// returns true if the element is situated in the tree
	node<T>* find(T elem) ;					// returns the pointer to the element in the tree
	node<T>* erase(node<T>* n, T elem);		// removes the node
	void erase(T elem) ;					// removes the element
	void print(node<T> *cur) ;				// inorder sub-tree
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
void bst<T>:: clear(){
	clear(root) ;
}

template<typename T>
void bst<T>:: clear(node<T> *cur ){
	if(cur == nullptr)
		return ;
	clear(cur->left) ;	// delete left sub-tree
	clear(cur->right) ;	// delete right sub-tree
	delete cur ;		// delete root
	_size-- ;
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
node<T>* bst<T>:: erase(node<T> *n, T key){
	if(n == nullptr)			// key not found
		return nullptr ;

	if(key < n-> data)						// key can be found in left
		n-> left = erase(n-> left, key) ;
	else if(key > n-> data)					// key can be found in right
		n-> right = erase(n-> right, key) ;
	else{									// found here
		if(n-> left == nullptr && n-> right == nullptr){	//	no child
			if(n == root)
				root = nullptr ;
			delete n ;
			_size-- ;
			return nullptr ;
		}
		else if(n-> left != nullptr && n-> right == nullptr){	// one child(left)
			node<T> *ret = n->left ;
			delete n ;
			_size-- ;
			return ret ;
		}
		else if(n-> left == nullptr && n-> right != nullptr){	// one child(right)
			node<T> *ret = n->right ;
			delete n ;
			_size-- ;
			return ret ;
		}
		else{		// no child
			node<T> *s = inorder_successor(key) ;		// replace with the inorder successor then recursively earase the previous position of that inorder successor
			T key2 = s-> data ;
			s = erase(root, s-> data) ;
			n-> data = key2 ;
			return n ;
		}
	}
}

template<typename T>
void bst<T>:: erase(T elem){
	root = erase(root, elem) ;
}

template<typename T>
void bst<T>:: print(node<T>* cur ){
	if(cur == nullptr)	return ;
	
	print(cur->left) ;						// process left sub-tree
	std:: cout << cur-> data << " " ;		// process the root
	print(cur-> right);						// process right sub-tree
}

#endif