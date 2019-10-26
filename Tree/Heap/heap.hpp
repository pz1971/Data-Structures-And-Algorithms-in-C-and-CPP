#ifndef _HEAP_HPP
#define _HEAP_HPP

#include <iostream>

template<typename T>
class heap{
private:
	T *array ;						// the abstract container that is going to act as heap
	size_t _mxSize, _size ;			// variables to store the value of max size and current size of the heap

public:
	heap() ;						// default constructor ... max len = 127
	heap(const int len) ;			// constructor with max len parameter
	~heap() ;						// destructor
	void clear() ;					// clears the heap
	size_t max_size() ;				// maximum size of the heap
	size_t size() ;					// current size of the heap
	bool empty() ;					// returns true if empty
	void insert(const T key) ;		// inserts the key in the heap
	T top() ;						// returns the value of the top(root) element of the heap
	void pop() ;					// removes the top element of the heap
};

template<typename T>
heap<T>:: heap() {
	array = new T [128] ;			// memory allocation
	_mxSize = 127 ;					// max size = 127
	_size = 0 ;						// current size is 0
}

template<typename T>
heap<T>:: heap(const int len) {
	array = new T [len + 1] ;		// memory allocation according to the parameter
	_mxSize = len ;					// max size = func param
	_size = 0 ;						// current size is 0
}

template<typename T>
heap<T>:: ~heap() {
	delete [] array ;				// deallocates the container memory
}

template<typename T>
void heap<T>:: clear() {
	_size = 0 ;						// size is 0 means no element in the heap
}

template<typename T>
size_t heap<T>:: max_size(){
	return _mxSize ;
}

template<typename T>
size_t heap<T>:: size(){
	return _size ;
}

template<typename T>
bool heap<T>:: empty(){
	return (_size == 0) ;			// size of an empty heap is 0
}

template<typename T>
void heap<T>:: insert(const T key){
	if(_size + 1 > _mxSize){		// attempt to insert more number of elements than it can contain
		std:: cerr<< "Error: container array out of bound..." << std:: endl ;		// printing error dialogue message
		return ;					// returns emmidately
	}

	_size++ ;						// one element is going to be inserted
	size_t pos = _size ;			// to maintain a complete binary tree- we add new elements sequentially
	
	while(pos != 1 && array[pos / 2] < key) {		// cuurent position (pos) is not the root (1st element) but the parent floor(pos/2) is smaller than the child
		array[pos] = array[pos / 2] ;				// smaller elements going towards leaf
		pos /= 2 ;									// actual postion of the child to be insert
	}

	array[pos] = key ;				// inserting the key to its place
}

template<typename T>
T heap<T>:: top(){
	if( empty() ){					// heap is empty
		std:: cerr << "Error: Heap is currently empty." << std:: endl ;
		exit(0) ;					// program terminates
	}

	return array[1] ;
}

template<typename T>
void heap<T>:: pop(){
	array[1] = array[_size] ;		// replace root/top with the last element
	_size-- ;						// one element has been removed

	int pos = 1 ;					// current postion of the last element... it should be inserted in its right place
	
	while(pos * 2 <= _size){		// not the leaf
		int left_child = pos * 2 ;
		int right_child = pos * 2 + 1 ;

		if(right_child > _size || array[left_child] > array[right_child]){		// right child doesn't exist Or left child is greater than the right one
			if(array[pos] >= array[left_child])
				break ;
			else {					// swap with left child
				//	// swap begins
				T temp = array[pos] ;
				array[pos] = array[left_child] ;
				array[left_child] = temp ;
				//	// swap end
				pos = left_child ;		// updating the current position...
			}
		}
		else{						// both child exist	and the right child is greater than the left
			// swap with the right child
			//	// swap begins
			T temp = array[pos] ;
			array[pos] = array[right_child] ;
			array[right_child] = temp ;
			//	// swap end
			pos = right_child ;		// updating the current position...
		}
	}
}

template<typename T>
void heapify(T ar[], int mx_sz, int root){
	int largest = root ;					// let root is has the largest element
	int left = root * 2 + 1 ;				// left child
	int right = root * 2 + 2 ;				// right child

	if(left < mx_sz && ar[left] > ar[largest])		// left child is larger/ the largest
		largest = left ;

	if(right < mx_sz && ar[right] > ar[largest])	// right child is the largest
		largest = right ;
	
	if(largest != root){
		// swap with the root
		T temp = ar[root] ;
		ar[root] = ar[largest] ;
		ar[largest] = temp ;
		// end of swap
		
		heapify(ar, mx_sz, largest) ;		// heapify the subtree that has been changed
	}
}

template<typename T>
void heapSort(T ar[], int mx_sz){
	for(int i = mx_sz / 2 - 1 ; i >= 0 ; i--)		// building the heap
		heapify(ar, mx_sz, i) ;
	
	for(int i = mx_sz - 1 ; i >= 0 ; i--){
		// root is the max... it goes to the end in a sorted array
		// swap	with the last element
		T temp = ar[0] ;
		ar[0] = ar[i] ;
		ar[i] = temp ;
		//
		// the last element has been fixed... now heapify the changed heap(1 smaller than previous operation)
		heapify(ar, i, 0) ;
	}
}

#endif