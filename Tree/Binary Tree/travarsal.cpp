#include <iostream>
#include <stack>		// stl
#include "linked_binary_tree.hpp"

using namespace std ;

void inorder_recursive(node<int> *root){		// root of int data type
	if(root->left != nullptr){
		inorder_recursive(root->left) ;		// process the left sub-tree
	}
	
	cout << root->data << " " ;			// process the root

	if(root->right != nullptr){
		inorder_recursive(root->right) ;		// process the right sub-tree
	}
}

void inorder_iterative(node<int> *root){
	stack< node<int>* > stk ;	// stack of pointers of node<int>
	node<int> *cur = root ;
	
	while(cur != NULL || !stk.empty()){
		// go as deep as you can :D ***go from left
		while(cur != nullptr){
			stk.push(cur) ;		// pushing current node
			cur = cur-> left ;		// going deeper from left side until I can't :D
		}

		cur = stk.top() ;	// deepest node unvisited is in the top of the stack
		stk.pop() ;			// popping it out
		cout << cur-> data << " " ;		// processing the current node

		cur = cur-> right ;	// now I can go right :D
	}
}

void preorder_recursive(node<int> *root){		// root of int data type
	cout << root->data << " " ;			// process the root
	
	if(root->left != nullptr){
		preorder_recursive(root->left) ;		// process the left sub-tree
	}

	if(root->right != nullptr){
		preorder_recursive(root->right) ;		// process the right sub-tree
	}
}

void preorder_iterative(node<int> *root){
	stack< node<int>* > stk ;	// stack of pointers of node<int>
	stk.push(root) ;		// starting with root :D

	while(!stk.empty()){		// until the stack is empty
		node<int> *cur = stk.top() ;	// taking the topmost element of the stack
		stk.pop() ;		// popping it out

		cout << cur->data << " " ;	// processing current node

		if(cur->right != nullptr)
			stk.push(cur-> right) ;		// why pushing the right first? Cuase: right will be popped later than left :D so, left will be processed first according to LIFO
		if(cur-> left != nullptr)
			stk.push(cur->left) ;		// pushing left
	}
}

void postorder_recursive(node<int> *root){		// root of int data type
	if(root->left != nullptr){
		postorder_recursive(root->left) ;		// process the left sub-tree
	}
	
	if(root->right != nullptr){
		postorder_recursive(root->right) ;		// process the right sub-tree
	}

	cout << root->data << " " ;			// process the root
}

void postorder_iterative(node<int> *root){
	stack< node<int>* > stk ;	// stack of pointers of node<int>
	stack< node<int>* > output ;	// output will be stored here :D
	
	stk.push(root) ;	// pushing the root
	
	while(!stk.empty()){		// until the stack is empty
		node<int> *cur = stk.top() ;		// taking the topmost element as the current node
		stk.pop() ;			// popping it out

		output.push(cur) ;		// pushing current node to output stack...

		if(cur-> left != nullptr)
			stk.push(cur-> left) ;		// pushing left child if has
		if(cur-> right != nullptr)
			stk.push(cur-> right) ;		// pushing right child if has
	}

	while(!output.empty()){			// processing all nodes
		cout << output.top()-> data << " " ;
		output.pop() ;
	}
}

int main(){
	
	binary_tree<int> myTree(1) ;	// root is 1 ;
	myTree.connect_left(myTree.root, new node<int>(2)) ;
	myTree.connect_right(myTree.root, new node<int>(3)) ;

	// cout << myTree.root->data << endl ;
	// cout << myTree.root->left->data << endl ;
	// cout << myTree.root->right->data << endl ;

	myTree.connect_left(myTree.root->left, new node<int>(4)) ;
	myTree.connect_right(myTree.root->left, new node<int>(5)) ;

	myTree.connect_left(myTree.root->right, new node<int>(6)) ;
	myTree.connect_right(myTree.root->right, new node<int>(7)) ;

	inorder_iterative(myTree.root) ;
	cout << endl ;
	inorder_recursive(myTree.root) ;
	cout << endl ;
	preorder_iterative(myTree.root) ;
	cout << endl ;
	preorder_recursive(myTree.root) ;
	cout << endl ;
	postorder_iterative(myTree.root) ;
	cout << endl ;
	postorder_recursive(myTree.root) ;
	cout << endl ;

	return 0 ;
}