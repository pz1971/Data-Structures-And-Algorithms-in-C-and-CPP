#ifndef STACK_LIST_HPP
#define STACK_LIST_HPP

#include <iostream>
#include <memory>

template<typename T>
class stack_list
{
private:
	class node{
	public:
		T data;		// the actual data to be stored
		node *next;		// pointer to the next node
	} *head;	// address of the head

	size_t _size ;	// the current size of the list

public:
	stack_list() ;							// constructor
	~stack_list() ;						// destructor
	void clear() ;							// clears the stack
	bool empty() ;							// returns true if empty else false
	size_t size() ;							// returns the _size, current size of the stack
	void push(T val) ;			// insert val at the beginning
	void pop() ;					// erases the element at the front ( right most element )
	T top() ;								// data of the top elemnt
};

template<typename T>
stack_list<T>:: stack_list(){
	head = nullptr ;	// stack is empty
	_size = 0;		// so the size is 0;
}

template<typename T>
stack_list<T>:: ~stack_list(){
	clear();		// clears the stack... meanwhile, de-allocates all the spaces consumed ;
}

template<typename T>
void stack_list<T>:: clear(){
	node *cur ;
	while(head != nullptr){		// de-allocating all the nodes
		cur = head ;
		head = head->next ;

		delete cur;			// de-allocation
	}

	_size = 0 ;		// size reset to 0
}

template<typename T>
bool stack_list<T>:: empty(){
	return ( _size == 0 ) ;		// empty stack has size  0 
}

template<typename T>
size_t stack_list<T>:: size(){
	return _size ;		// returning the size ;
}

template<typename T>
void stack_list<T>:: push(T val){
	node *temp = new node();	// allocating a new node;
	
	temp->data = val;	// assigning value to the new node's data
	temp->next = head;	// current head will sit next to the temp
	head = temp;		// temp is the new head! :D
	
	_size++;		// size increasd by 1
}

template<typename T>
void stack_list<T>:: pop(){
	if( empty() )		// nothing to erase
		return ;
	if(_size == 1){
		clear() ;	// deleting 1 element causes it to be cleared
		return ;
	}

	node *temp = head ;
	head = head->next ;	// head is pointing to the second element now...
	delete temp ;	// delete the first element

	_size--;
}

template<typename T>
T stack_list<T>:: top(){
	try{
		if(head == nullptr){	// list is empty
			throw 0;	// throws exception
		}
		else{
			return head->data ;	// returns desired value
		}
	}
	catch(int e){
		std:: cerr << "Error: list is currently empty..." << std:: endl ; // error message
		exit( 0 ) ;	// program termitates
	}
}

#endif