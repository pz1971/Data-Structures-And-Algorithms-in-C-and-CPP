#ifndef _TRIE_HPP
#define _TRIE_HPP

#include <iostream>
#include <string>
using namespace std ;

const int ALPHABET_SIZE = 128 ;

class trie{
private:
	class node{			// inner class
	public:
		int completeCount ;	// number of complete string
		int childCount ;		// total number of child
		node *child[ALPHABET_SIZE] ;
		node(){
			completeCount = childCount = 0 ;
			for(int i = 0 ; i < ALPHABET_SIZE ; i++)
				child[i] = nullptr ;
		}
	} ;
	node *root ;

	void print(node *cur, string &str , const char token) ;	// called from ...print(const char token = '\n')...
	void clear(node *cur) ;	// clears the subtree from node cur
public:
	trie() ;		// constructor
	~trie() ;		// destructor
	void clear() ;	// clears the container
	bool empty() ;	// returns true if the container is empty
	size_t size() ;	// current size of the trie
	void insert(const string &str) ;	// inserts the string in trie
	void remove(const string &str) ;	// removes the string if exists
	int count(const string &str) ;		// returns the number of how many times str has appeared in the trie
	int suffixCount(const string &str) ;		// returns the number of strings those have  str  as prefix
	int prefixCount(const string &str) ;		// returns the number of strings whose prefix is  str
	bool search(const string &str) ;	// returns true if  str  exists in the trie
	void print(const char token = '\n') ;		// prints all element... tokens are added after each element
} ;

trie:: trie(){
	root = new node() ;
}

trie:: ~trie(){
	clear(root) ;
}

void trie:: clear(){
	clear(root) ;
	root = new node() ;
}

void trie:: clear(node *cur){
	for(int i = 0 ; i < ALPHABET_SIZE ; i++)
		if(cur -> child[i] != nullptr)
			clear(cur -> child[i]) ;
	delete cur ;
}

bool trie:: empty(){
	return (root -> childCount == 0) ;
}

size_t trie:: size(){
	return root -> childCount ;
}

void trie:: insert(const string &str){
	node *cur = root ;
	cur -> childCount++ ;
	
	for(const auto &ch : str){
		if(cur -> child[ch] == nullptr)
			cur -> child[ch] = new node() ;

		cur = cur -> child[ch] ;
		cur -> childCount++ ;
	}
	cur -> completeCount++ ;
}

void trie:: remove(const string &str){
	if(! search(str))	// doesn't exist
		return ;
	
	node *cur = root ;
	for(const auto &i : str){
		cur -> childCount-- ;
		cur = cur -> child[i] ;
	}
	cur -> childCount-- ;
	cur -> completeCount-- ;

	cur = root ;
	for(const auto &i : str){
		if(cur -> childCount == 0){
			clear(cur -> child[i]) ;
			break ;
		}
	}
}

int trie:: count(const string &str){
	node *cur = root ;

	for(const auto &ch : str){
		if(cur -> child[ch] == nullptr)
			return 0 ;
		cur = cur -> child[ch] ;
	}
	return cur -> completeCount ;
}

int trie:: suffixCount(const string &str){
	node *cur = root ;

	for(const auto &ch : str){
		if(cur -> child[ch] == nullptr)
			return 0 ;
		cur = cur -> child[ch] ;
	}
	return cur -> childCount ;
}

int trie:: prefixCount(const string &str){
	node *cur = root ;
	int ret = 0 ;

	for(const auto &ch : str){
		if(cur -> child[ch] == nullptr)
			break ;
		cur = cur -> child[ch] ;
		ret += cur -> completeCount ;
	}
	return ret ;
}

bool trie:: search(const string &str){
	return (bool) (count(str) > 0) ;
}

void trie:: print(node *cur, string &str , const char token){
	if(cur -> completeCount > 0){
		for(int i = 0 ; i < cur->completeCount ; i++)
			cout << str << token ;
	}

	for(int i = 0 ; i < ALPHABET_SIZE ; i++)
		if(cur -> child[i] != nullptr){
			str.push_back(i) ;
			print(cur -> child[i], str, token) ;
			str.pop_back() ;
		}
}

void trie:: print(const char token){
	string str = "" ;
	print(root, str, token) ;
}

#endif