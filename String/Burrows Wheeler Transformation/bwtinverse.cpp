#include <bits/stdc++.h>
using namespace std ;

string InverseBWT(const string &bwt)
{
	string text = "";
	string left_col = bwt ;
	sort(left_col.begin(), left_col.end()) ;
	
	map<char, int> cnt ;
	vector<int> id(bwt.size()) ;
	for(int i = 0 ; i < bwt.size() ; i++){
		id[i] = cnt[ bwt[i] ]++ ;
	}

	int cur = 0 ;
	do{
		text.push_back(left_col[cur]) ;
		char temp = bwt[cur] ;
		cur = lower_bound(left_col.begin(), left_col.end(), temp) - left_col.begin() + id[cur] ;
	}while(cur != 0) ;

	reverse(text.begin(), text.end()) ;
	return text;
}

int main()
{
	string bwt;
	cin >> bwt;
	cout << InverseBWT(bwt) << endl;
	return 0;
}
