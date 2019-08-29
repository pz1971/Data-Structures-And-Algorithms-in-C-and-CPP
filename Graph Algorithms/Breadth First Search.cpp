// Breadth First Search (shortest path algorithm)
// Time Complexity	:	O(N + E)	where, N = number of vertices, E = number of edges
// Restriction		:	Works for only unweighted graphs
//
// Algorithm	:	(collected from: hackerearth.com)
// BFS (G, s)                   //Where G is the graph and s is the source node
//       let Q be queue.
//       Q.enqueue( s ) //Inserting s in queue until all its neighbour vertices are marked.

//       mark s as visited.
//       while ( Q is not empty)
//            //Removing that vertex from queue,whose neighbour will be visited now
//            v  =  Q.dequeue( )

//           //processing all the neighbours of v  
//           for all neighbours w of v in Graph G
//                if w is not visited 
//                         Q.enqueue( w )             //Stores w in Q to further visit its neighbour
//                         mark w as visited.

#include <vector>
#include <queue>
#define MX 100		// maximum number of elements

vector<int> adj_list[MX];		// all the elements of adj_list[i] is are directly connected to i
int vis[MX];				// vis[i] >= 1 if ith node has already been visited

void bfs(int s){		// find the length of the shortest path form s to all the connected elements
	queue<int> q;	// a queue of integers
	q.push(s) ;		// push s to the queue
	vis[s] = 1;		// s is now visited... no need to visit again

	while(!q.empty()){	// repeat until the q is empty
		int cur = q.front() ;	// get the front-most element from the queue, that is to be processed now
		q.pop() ;		// remove the current element cur from the queue

		for(int i : adj_list[ cur ]){
			if(vis[i] == 0){	// i is not visited yet and also not in the queue
				q.push(i) ;		// push it in the queue
				vis[i] = 1;		// i is ready to be visited
			}
		}
	}
}