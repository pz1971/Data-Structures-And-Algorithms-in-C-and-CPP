#include <bits/stdc++.h>
using   namespace  std ;

class Bucket{
private:
	class Node{
	public:
		int key ;
		Node *next ;
		Node(int key){
			this-> key = key ;
			next = nullptr ;
		}
	} *head ;

public:
	Bucket(){
		head = nullptr ;
	}

	void insert(int key){
		if(head == nullptr){	// list was empty
			head = new Node(key) ;
			return ;
		}

		if(key < head->key){
			Node *temp = new Node(key) ;
			temp-> next = head ;
			head = temp ;
			return ;
		}

		Node *cur = head ;
		while(cur -> next && cur -> key < key)
			cur = cur -> next ;
		Node *temp = new Node(key) ;
		temp -> next = cur -> next ;
		cur -> next = temp ;
	}

	bool empty(){
		return (head == nullptr) ;
	}

	int pop(){
		int ret = head -> key ;
		head = head -> next ;
		return ret ;
	}
} ;

int n, mx ;

inline int indx(int key){
	return key * n / (mx + 1) ;	//   value * array_len / (maximum element + 1)
}

void bucket_sort(int ar[]){
	Bucket b[n] ;
	for(int i = 0 ; i < n; i++){
		b[indx(ar[i])].insert(ar[i]) ;
	}

	int idx = 0 ;
	for(int i = 0 ; i < n ; i++){
		while(!b[i].empty()){
			ar[idx++] = b[i].pop() ;
		}
	}
}

int main(){

	cin >> n ;
	int ar[n] ;
	mx = 0 ;
	
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i] ;
		mx = max(mx, ar[i]) ;
	}

	bucket_sort(ar) ;

	for(int i = 0 ; i < n; i++)
		cout << ar[i] << " " ;
	cout << endl ;

	return 0;
}