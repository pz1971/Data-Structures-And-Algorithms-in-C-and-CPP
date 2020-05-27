vector<int> SortCharacters(const string &s){
	vector<int> order(s.size()) ;
	map<char, int> count ;

	for(char i : s)
		count[i]++ ;
	for(auto i = count.begin() ; i != count.end() ; i++){
		auto j = i ; j++ ;
		j -> second += i -> second ;
	}
	for(int i = s.size() - 1 ; i >= 0 ; i--){
		order[--count[s[i]]] = i ;
	}
	return order ;
}

vector<int> ComputeCharClasses(const string &s, const vector<int> &order){
	vector<int> _class(s.size()) ;
	_class[order[0]] = 0 ;
	for(int i = 1 ; i < s.size() ; i++){
		if(s[order[i]] != s[order[i-1]])
			_class[order[i]] = _class[order[i-1]] + 1 ;
		else 
			_class[order[i]] = _class[order[i-1]] ;
	}
	return _class ;
}

vector<int> SortDoubled(const string &s, const int L, const vector<int> &order, const vector<int> &_class){
	vector<int> count(s.size(), 0) ;
	vector<int> newOrder(s.size()) ;
	for(int i = 0 ; i < s.size() ; i++){
		count[_class[i]]++ ;
	}
	for(int i = 1 ; i < s.size() ; i++){
		count[i] += count[i-1] ;
	}
	for(int i = s.size() - 1 ; i >= 0 ; i--){
		int start = (order[i] - L + (int)s.size()) % (int)s.size() ;
		int cl = _class[start] ;
		count[cl]-- ;
		newOrder[count[cl]] = start ;
	}
	return newOrder ;
}

vector<int> UpdateClasses(const vector<int> &newOrder, const vector<int> &_class, const int L){
	int n = newOrder.size() ;
	vector<int> newClass(n) ;
	newClass[newOrder[0]] = 0 ;
	
	for(int i = 1 ; i < n ; i++){
		int cur = newOrder[i] ;
		int prev = newOrder[i-1] ;
		int mid = (cur + L) % n ;
		int mid_prev = (prev + L) % n ;
		if(_class[cur] != _class[prev] || _class[mid] != _class[mid_prev])
			newClass[cur] = newClass[prev] + 1 ;
		else 
			newClass[cur] = newClass[prev] ;
	}
	return newClass ;
}

vector<int> BuildSuffixArray(const string &s)
{
	vector<int> order = SortCharacters(s);
	vector<int> _class = ComputeCharClasses(s, order) ;
	int L = 1 ;
	while(L < s.size()){
		order = SortDoubled(s, L, order, _class) ;
		_class = UpdateClasses(order, _class, L) ;
		L = 2 * L ;
	}
	return order;
}

int cmp(const string &pattern, const string &text, int pos){
	for(int i = 0 ; i < pattern.size() ; i++){ 
		if(pattern[i] < text[i + pos]) // won't exceed text.size() because of '$'
			return 0 ;
		else if(pattern[i] > text[i + pos]) // won't exceed text.size() because of '$'
			return 2 ;
	}
	return 1 ;
}

vector<int> FindOccurrences(const string &pattern, const string &text, const vector<int> &suffix_array)
{
	vector<int> result;

	int lo = 0, hi = text.size() - 1, mid, pos = -1 ;
	while(lo <= hi){
		mid = (lo + hi) / 2 ;
		int x = cmp(pattern, text, suffix_array[mid]) ;
		
		if(x == 1){
			pos = mid ;
			hi = mid - 1 ;
		}
		else if(x == 0){
			hi = mid - 1 ;
		}
		else{
			lo = mid + 1 ;
		}
	}

	if(pos == -1)	// no occurrences.
		return result ; // empty vector

	lo = 0, hi = text.size() - 1 ;
	int pos2 = -1 ;

	while(lo <= hi){
		mid = (lo + hi) / 2 ;
		int x = cmp(pattern, text, suffix_array[mid]) ;

		if(x == 1){
			pos2 = mid ;
			lo = mid + 1 ;
		}
		else if(x == 0){
			hi = mid - 1 ;
		}
		else{
			lo = mid + 1 ;
		}
	}

	for(int i = pos ; i <= pos2 ; i++){
		result.push_back(suffix_array[i]) ;
	}

	return result;
}