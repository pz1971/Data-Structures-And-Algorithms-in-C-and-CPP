#include <bits/stdc++.h>
using   namespace  std ;

const int inf = INT_MAX ;
typedef vector<vector<int>> MAT ;

void print(MAT m){
	for(auto i : m){
		for(auto j : i){
			cout << setw(12) << j ;
		}
		cout << endl ;
	}
	cout << endl ;
}

class node{
public:
	MAT mat ;			// cost matrix
	vector<int> path ; 	// contains the nodes of the path
	int cur ;			// current node index
	int par ;			// parent node index
	int cost ;			// reduced cost
	int reduce() ;		// reduces the cost matrix

	node(vector<int> _path, int _cur, int _par, int par_cost, int vis_cost, MAT _mat){
		path = _path ;	path.push_back(_cur) ;
		cur = _cur ;
		par = _par ;
		mat = _mat ;
		
		if(par != -1)
			mat[cur][par] = inf ;
		cost = par_cost + vis_cost + reduce() ;
	}
};

int node::reduce(){
	int sum = 0 ;
	int sz = mat.size() ;
	// row reduction
	for(int i = 0 ; i < sz; i++){
		int mn = inf ;

		if(i == par){
			for(int j = 0 ; j < sz ; j++)
				mat[i][j] = inf ;
			continue ;
		}

		for(int j = 0 ; j < sz ; j++)
			mn = min(mn, mat[i][j]) ;
		for(int j = 0 ; j < sz ; j++)
			if(mat[i][j] != inf)
				mat[i][j] -= mn ;
		if(mn != inf)
			sum += mn ;
	}
	// column reduction 
	for(int i = 0 ; i < sz; i++){
		int mn = inf ;

		if(i == cur && par != -1){
			for(int j = 0 ; j < sz ; j++)
				mat[j][i] = inf ;
			continue ;
		}

		for(int j = 0 ; j < sz ; j++)
			mn = min(mn, mat[j][i]) ;
		for(int j = 0 ; j < sz ; j++)
			if(mat[j][i] != inf)
				mat[j][i] -= mn ;
		if(mn != inf)
			sum += mn ;
	}

	return sum ;
}

class cmp{
public:
	bool operator () (const node &n1, const node &n2){
		return (n1.cost > n2.cost) ;
	}
};

node TSP(const int s, const MAT &cost_mat){
	int sz = cost_mat.size() ;

	node source(vector<int>(0) , s, -1, 0, 0, cost_mat) ;
	priority_queue<node, vector<node>, cmp> pq ;
	pq.push(source) ;

	while(!pq.empty()){
		node temp = pq.top() ;
		pq.pop() ;

		if(temp.path.size() == sz){
			temp.path.push_back(s) ;
			return temp ;
		}

		for(int i = 0 ; i < sz ; i++){
			if(temp.mat[temp.cur][i] != inf)
				pq.push( node(temp.path, i, temp.cur, temp.cost, temp.mat[temp.cur][i], temp.mat) ) ;
		}
	}
}

int main(){

	int n;
	cin >> n ;

	MAT cost_mat(n, vector<int>(n, inf)) ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i != j)
				cin >> cost_mat[i][j] ;
		}
	}

	node ans = TSP(0, cost_mat) ;

	cout << "Path : " ;
	for(auto i : ans.path)
		cout << i << " " ;
	cout << endl ;
	cout << "Total Cost = " << ans.cost << endl ;

	return 0;
}