#include <iostream>

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

int main(){

    int ar[] = {7, 2, 6, 5, 1, 3, 4} ;
    heapSort(ar, 7) ;

    for(int i = 0 ; i < 7 ; i++)
        std:: cout << ar[i] << " \n"[i==6] ;    // 1 2 3 4 5 6 7

    return 0 ;
}