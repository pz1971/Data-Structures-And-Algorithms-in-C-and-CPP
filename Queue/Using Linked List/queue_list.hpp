#ifndef QUEUE_LIST_HPP
#define QUEUE_LIST_HPP

#include <iostream>
#include <memory>

template<typename T>
class queue_list
{
private:
	class node{
	public:
		T data;		// the actual data to be stored
		node *next;		// pointer to the next node
	} *head, *tail;	// address of the head and tail

	size_t _size ;	// the current size of the list

public:
	queue_list() ;							// constructor
	~queue_list() ;						// destructor
	void clear() ;							// clears the queue
	bool empty() ;							// returns true if empty else false
	size_t size() ;							// returns the _size, current size of the queue
	void push(T val) ;			// insert val at the beginning
	void pop() ;					// erases the element at the front ( right most element )
	T front() ;								// data of the first elemnt
};

template<typename T>
queue_list<T>:: queue_list(){
	head = tail = nullptr ;	// queue is empty
	_size = 0;		// so the size is 0;
}

template<typename T>
queue_list<T>:: ~queue_list(){
	clear();		// clears the queue... meanwhile, de-allocates all the spaces consumed ;
}

template<typename T>
void queue_list<T>:: clear(){
	node *cur ;
	while(head != nullptr){		// de-allocating all the nodes
		cur = head ;
		head = head->next ;

		delete cur;			// de-allocation
	}

	_size = 0 ;		// size reset to 0
}

template<typename T>
bool queue_list<T>:: empty(){
	return ( _size == 0 ) ;		// empty queue has size  0 
}

template<typename T>
size_t queue_list<T>:: size(){
	return _size ;		// returning the size ;
}

template<typename T>
void queue_list<T>:: push(T val){
	node *temp = new node();	// allocating a new node;
	temp->data = val ;	// assigning value to the new node's data
	temp->next = nullptr ;
	
	if(head == nullptr){	// the list is empty 
		head = tail = temp ;
	}
	else{
		tail->next = temp ;		// pushing to the end
		tail = temp ;			// temp is the new tail :D
	}

	_size++;		// size increasd by 1
}

template<typename T>
void queue_list<T>:: pop(){
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
T queue_list<T>:: front(){
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