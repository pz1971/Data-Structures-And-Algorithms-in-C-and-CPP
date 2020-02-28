const int mx = 1005 ;
int n, p[mx], w[mx], dp[mx][35] ;

void knapsack(){
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j < 33 ; j++){
			if(j - w[i] >= 0)
				dp[i][j] = max(dp[i-1][j], p[i] + dp[i-1][j - w[i]]) ;
			else
				dp[i][j] = dp[i-1][j] ;
		}
	}
}
vector<int> selected(int n, int w){
	int cur = dp[n][w] ;
	vector<int> ret ;	// list of the items selected

	for(int i = n ; i > 0 ; i--){
		if(cur == dp[i-1][w])
			continue ;
		ret.push_back(i) ;
		cur -= p[i] ;
		w -= w[i] ;
	}
	sort(ret.begin(), ret.end()) ;
	return ret ;
}