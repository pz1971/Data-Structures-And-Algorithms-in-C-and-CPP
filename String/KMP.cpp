vector<int> find_all_occurrences(const string &pattern, const string &text)
{
	vector<int> result;
	
	string s = pattern + '$' + text ;
	vector<int> pi(s.size()) ;

	pi[0] = 0 ;
	int j = 0 ;
	for(int i = 1 ; i < s.size() ; i++){
		while(j > 0 && s[i] != s[j])
			j = pi[j-1] ;
		if(s[i] == s[j])
			pi[i] = ++j ;
	}

	// if pattern ends at position i, the prefix funtion of i will be equal to pattern.size() 
	for(int i = pattern.size() + 1 ; i < s.size() ; i++){
		if(pi[i] == pattern.size())
			result.push_back(i - 2 * pattern.size()) ;
	}

	return result;
}