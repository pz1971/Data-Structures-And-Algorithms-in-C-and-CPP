string add_special_character(const string &s){
	string ret ;
	for(auto i : s){
		ret.push_back('$') ;
		ret.push_back(i) ;
	}
	ret.push_back('$') ;
	return ret ;
}

int manacher(const string &str){
	string s = add_special_character(str) ;
	vector<int> lps(s.size(), 0) ;
	
	int c = 0, r = 0 ;
	int mx_len = 0 ;

	for(int i = 0 ; i < s.size() ; i++){
		int mirror = c + c - i ;
		if(i < r){
			lps[i] = min(r - i, lps[mirror]) ;
		}

		int a = i + (1 + lps[i]) ;
		int b = i - (1 + lps[i]) ;

		while(a < s.size() && b >= 0 && s[a] == s[b]){
			lps[i]++ ;
			a++ ;
			b-- ;
		}

		if(i + lps[i] > r){
			c = i ;
			r = i + lps[i] ;

			mx_len = max(mx_len, lps[i]) ;
		}
	}

	return mx_len ;
}