// Depth First Search, (Graph travarsing algorithm)
// Time Complexity	:	O(N + E)	where, N = number of vertices, E = number of edges
//
// Algorithm:	(collected from wikipedia)

// 1  procedure DFS(G,v):
// 2      label v as discovered
// 3      for all directed edges from v to w that are in G.adjacentEdges(v) do
// 4          if vertex w is not labeled as discovered then
// 5              recursively call DFS(G,w)

// 1  procedure DFS-iterative(G,v):
// 2      let S be a stack
// 3      S.push(v)
// 4      while S is not empty
// 5          v = S.pop()
// 6          if v is not labeled as discovered:
// 7              label v as discovered
// 8              for all edges from v to w in G.adjacentEdges(v) do 
// 9                  S.push(w)

#include <vector>
#include <stack>
#define MX 100			// number of elements

vector<int> adj_list[MX];		// all the elements of adj_list[i] is are directly connected to i
int vis[MX];				// vis[i] >= 1 if ith node has already been visited

void recursive_dfs(int s){	// s is the starting node
	vis[s] = 1 ;				// first visit the source 

	for(int i : adj_list[s]){	// iterate over all the connected nodes from s
		if(vis[i] == 0){		// if i is not visited yet
			recursive_dfs(i) ;	// visit it... hence run another dfs with source i
		}
	}
}

void iterative_dfs(int s){
	stack<int> st ;			// a stack of integers
	st.push(s) ;			// place s in the stack
	vis[s] = 1;				// s is visited now

	while(!s.empty()){			// untill the stack is empty
		int cur = st.top() ;		// get the top most element from the stack...
		st.pop();				// remove it from the stack...

		for(int i : adj_list[cur]){		//	get all the connected components to cur
			if(vis[i] == 0){		// i is not visited yet and also not in the stack
				st.push(i) ;		// place i in the stack
				vis[i] = 1;			// i is ready to be visited
			}
		}
	}
}
