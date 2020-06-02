class BIT{
private:
	int n ;
	vector<int> tree ;
public :
	BIT(int _size){ // constructor
		n = _size ;
		if(n > 0)
			tree = vector<int>(n, 0) ;
	}
	
	~BIT(){	// destructor
		tree.clear() ;
	}

	template<typename T>	// ar[] or std::vector<> of size = n
	void init(const T ar){	// O(n)
		for(int i = 1 ; i <= n ; i++){
			tree[i-1] += ar[i-1] ;
			if(i + (i & (-i)) <= n)
				tree[i + (i & (-i)) - 1] += tree[i-1] ;
		}
	}

	void add(int pos, int val){	// O(lg(n))
		while(pos <= n){
			tree[pos - 1] += val ;
			pos += pos & (-pos) ;
		}
	}
	int query(int pos){	// O(lg(n))
		int ret = 0 ;
		while(pos > 0){
			ret += tree[pos - 1] ;
			pos -= pos & (-pos) ;
		}
		return ret ;
	}
	int query(int l, int r){	// best O(1) avg O(lg(n))
		if(l == r)	return tree[l - 1] ;
		return (query(r) - query(l - 1)) ;
	}
} ;