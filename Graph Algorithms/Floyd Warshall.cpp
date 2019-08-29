// Floyd Warshall's all pair shortest path problem
// time complexity	:	O(n^3)

// Algorithm:		(collected from wikipedia)
// 1 let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)
// 2 for each edge (u,v)
// 3    dist[u][v] ← w(u,v)  // the weight of the edge (u,v)
// 4 for each vertex v
// 5    dist[v][v] ← 0
// 6 for k from 1 to |V|
// 7    for i from 1 to |V|
// 8       for j from 1 to |V|
// 9          if dist[i][j] > dist[i][k] + dist[k][j] 
// 10             dist[i][j] ← dist[i][k] + dist[k][j]
// 11         end if

//  -----------------------------------------------------------------------------  //

#include <cstdio>
#define MX 100					// 100 components in total
#define INF 1000000007			// A very large integers
int dis[MX][MX];					// dis[i][j] = 1 if i, j is connected else INF ;
int nxt[MX][MX] ;				// nxt[i][j] contains the id of the next node in the path from i to j

void floyd_warshall(){

	for(int i=0; i < MX ; i++){				//	this part is
		for(int j = 0; j < MX ; j++){		//	needed only
			nxt[i][j] = j ;					//	when you
		}									//	need to print 
	}										//	the shortest path

	for(int k = 0; k < MX ; k++){
		for(int i = 0; i < MX ; i++){
			for(int j = 0; j < MX ; j++){
				if(dis[i][j] > dis[i][k] + dis[k][j]){	// it's better visiting k form i first and then visit j from k
					dis[i][j] = dis[i][k] + dis[k][j] ;	// shortest distance updated
					
					nxt[i][j] = k ;		// if we want to print the shortest path
				}
			}
		}
	}
}

void print_path(int i, int j){		// print the shortest path from i to j
	if(dis[i][j] == INF){
		printf("NO PATH") ;		// if there is no path from i to j
	}
	else if(i == j){		// i and j are the same
		printf("%d\n", i);
	}
	else{
		while(i != j){
			printf("%d ", i);	// i'm here!
			i = nxt[i][j] ;		// i've moved myself to the next node on my path!
		}
		printf("%d\n", j);	// i'm on my destination! :D
	}
}