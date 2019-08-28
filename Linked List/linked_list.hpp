#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <memory>

template<typename T>
class linked_list
{
private:
	class node{
	public:
		T data;		// the actual data to be stored
		node *next;		// pointer to the next node
	} *head;	// address of the head

	size_t _size ;	// the current size of the list

public:
	linked_list() ;							// constructor
	~linked_list() ;						// destructor
	void clear() ;							// clears the list
	bool empty() ;							// returns true if empty else false
	size_t size() ;							// returns the _size, current size of the list
	void insert_front(int val) ;			// insert val at the beginning
	void insert_back(int val) ;				// insert val at the end
	void insert_at(size_t pos, int val) ;	// insert the value at the index pos ( 0 indexed )...
	void erase_front() ;					// erases the element at the front ( right most element )
	void erase_back() ;						// erases the left most element
	void erase_at(size_t pos) ;				// erases the element lying at index pos.. if pos is valid
	T front() ;								// data of the first elemnt
	T back() ;								// data of the last element
	T at(size_t pos) ;						// data of the element lying at the index pos ( 0 indexed )
	T operator [] (size_t pos) ;			// as same as at( pos ) ;
	void print_list() ;						// prints all the elements ;
};

template<typename T>
linked_list<T>:: linked_list(){
	head = nullptr ;	// list is empty
	_size = 0;		// so the size is 0;
}

template<typename T>
linked_list<T>:: ~linked_list(){
	clear();		// clears the list... meanwhile, de-allocates all the spaces consumed ;
}

template<typename T>
void linked_list<T>:: clear(){
	node *cur ;
	while(head != nullptr){		// de-allocating all the nodes
		cur = head ;
		head = head->next ;

		delete cur;			// de-allocation
	}

	_size = 0 ;		// size reset to 0
}

template<typename T>
bool linked_list<T>:: empty(){
	return ( _size == 0 ) ;		// empty list has size  0 
}

template<typename T>
size_t linked_list<T>:: size(){
	return _size ;		// returning the size ;
}

template<typename T>
void linked_list<T>:: insert_front(int val){
	node *temp = new node();	// allocating a new node;
	
	temp->data = val;	// assigning value to the new node's data
	temp->next = head;	// current head will sit next to the temp
	head = temp;		// temp is the new head! :D
	
	_size++;		// size increasd by 1
}

template<typename T>
void linked_list<T>:: insert_back(int val){
	node *temp = new node();	// allocating a new node;
	temp->data = val ;	// assigning value to the new node's data
	temp->next = nullptr ;
	
	if(head == nullptr){	// the list is empty 
		insert_front(val) ;		// it's the same inserting at the beginning or at the end of an empty list 
		return ;
	}

	node *cur = head;
	while(cur->next != nullptr){	// iterate till cur is not the last node
		cur = cur->next ;
	}

	cur->next = temp ;	// cur is the new tail :D
	
	_size++;		// size increasd by 1
}

template<typename T>
void linked_list<T>:: insert_at(size_t pos, int val){
	if(pos == 0) {		// insert at the beginning
		insert_front(val);
		return ;
	}
	else if(pos == _size){	// insert at the end
		insert_back(val) ;
		return ;
	}
	else if(pos > _size){	// invalid position
		std:: cerr << "Error: index out of bound..." << std:: endl ;	// error message
		exit( 0 ) ;	// program termintes 
	}

	node *temp = new node() ;
	temp-> data = val ;		// creating new node to be placed in the list

	node *cur = head ;
	while(--pos){
		cur = cur->next ;	// get to the appropriate position
	}

	temp-> next = cur-> next ;
	cur-> next = temp ;		// placing the new node in the list

	_size++ ;		// size increased by 1 ;
}

template<typename T>
void linked_list<T>:: erase_front(){
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
void linked_list<T>:: erase_back(){
	if( empty() )		// nothing to erase
		return ;
	if(_size == 1){
		clear() ;	// deleting 1 element causes it to be cleared 
		return ;
	}

	node *cur = head, *temp = head ;
	while(cur -> next != nullptr){	// iterate to the end
		temp = cur ;
		cur = cur -> next ;
	}

	temp->next = nullptr ;	// remove the link to the last element
	delete cur ;	// deleting the last element

	_size--;	// size decreases by 1
}

template<typename T>
void linked_list<T>:: erase_at(size_t pos){
	if(_size == 0)
		return ;	// nothing to erase;
	if(pos >= _size){	// invalid index
		std:: cerr << "Error: Index out of bound..." << std:: endl ;
		exit( 0 ) ;
	}

	if(pos == 0){	// erase the first element
		erase_front() ;
	}
	else if(pos == _size - 1){	// erase the last element
		erase_back() ;
	}
	else{
		node *cur = head, *temp = head ;
		while(pos--){		// get to the right position
			temp = cur ;
			cur = cur-> next ;
		}

		temp->next = cur->next ;	// fix links
		delete cur ;	// delete that node ;

		_size--;	// size decreases by 1
	}
}

template<typename T>
T linked_list<T>:: front(){
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

template<typename T>
T linked_list<T>:: back(){
	try{
		if(head == nullptr){	// list is empty
			throw 0;	// throws exception
		}
		else{
			node *cur = head ;
			while(cur-> next != nullptr){	// get to the tail
				cur = cur->next ;
			}

			return cur->data ;	// returns desired value
		}
	}
	catch(int e){
		std:: cerr << "Error: list is currently empty..." << std:: endl ; // error message
		exit( 0 ) ;	// program terminates
	}
}

template<typename T>
T linked_list<T>:: at(size_t pos){
	if(pos >= _size){
		std:: cerr << "Error: index out of bound..." << std:: endl ; // error message
		exit( 0 ) ; // program terminates
	}

	node *cur = head ;
	while(pos--){		// get to the exact index
		cur = cur->next ;
	}

	return cur-> data ;	// return the data of that index
}

template<typename T>
T linked_list<T>:: operator [] (size_t pos){
	return at(pos) ;	// return the data at pos index
}

template<typename T>
void linked_list<T>:: print_list(){
	node *cur = head;

	while(cur != nullptr){		// print every data from the head till the end(nullptr)
		std:: cout << cur->data << " ";
		cur = cur->next ;
	}

	std:: cout<< "\n" ;
}


#endif