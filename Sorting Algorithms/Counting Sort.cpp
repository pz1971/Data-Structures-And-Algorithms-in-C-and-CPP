#include <iostream>
#include <cstring>
using namespace std ;

inline int indx(int key, int k){
	return (k + key) ;
}

void counting_sort(int ar[], int n, int k){
	int cnt[k * 2 + 1] ;		// the count array
	memset(cnt, 0, sizeof cnt);

	for(int i = 0 ; i < n ; i++){
		cnt[indx(ar[i], k)]++ ;		// counting
	}
	for(int i = 1 ; i < k * 2 + 1 ; i++){
		cnt[i] += cnt[i - 1] ;		// cumulative count
	}
	
	int temp[n + 1] ;	// temporary array to store sorted elements.
	for(int i = n - 1 ; i >= 0 ; i--){
		temp[cnt[indx(ar[i], k)]] = ar[i] ;
		cnt[indx(ar[i], k)]-- ;
	}

	for(int i = 0 ; i < n ; i++)
		ar[i] = temp[i + 1] ;
}

int main(){

	int n, k ;	// n = array len, k = maximum abs(element)
	cin >> n >> k ;

	int ar[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i] ;		// array input
	}

	counting_sort(ar, n, k) ;

	for(int i = 0 ; i < n;  i++){
		cout << ar[i] << " " ;
	}
	cout << endl ;

	return 0;
}