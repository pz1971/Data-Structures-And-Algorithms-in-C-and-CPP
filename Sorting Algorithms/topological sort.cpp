#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 10005 ;
vector<int> g[mx] ;
bool vis[mx] ;
stack<int> ans ;
int n;

void dfs(int s){
	vis[s] = 1 ;
	for(auto i : g[s])
		if(!vis[i])
			dfs(i) ;
	ans.push(s) ;
}

void top_sort(){
	memset(vis, 0, sizeof vis);
	for(int i = 1 ; i <= n ; i++)
		if(!vis[i])
			dfs(i) ;
}

int main(){

	int m ;
	cin >> n >> m ;
	int u, v ;

	while(m--){
		cin >> u >> v ;
		g[u].push_back(v) ;
	}

	top_sort() ;

	while(!ans.empty()){
		cout << ans.top() << " " ;
		ans.pop() ;
	}
	cout << endl ;

	return 0;
}