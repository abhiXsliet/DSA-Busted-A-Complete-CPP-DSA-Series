//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626
//Time & Space Complexity will be O(N+E) where N = no. of vertices and E = no. of edges

#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
	//prepare adjacency list
	unordered_map<int, list<int>> adj;
	for(int i=0; i<edges.size(); i++) {
		int u = edges[i].first - 1;
		int v = edges[i].second- 1;
		adj[u].push_back(v);
	}

	//find all indegree
	vector<int> indegree(n);
	for(auto i : adj) {
		for(auto j : i.second) {
			indegree[j] ++;
		}
	}

	//push 0-indegree's vertices into queue
	queue<int> q;
	for(int i=0; i<n; i++) {
		if(indegree[i] == 0) {
			q.push(i);
		}
	}
	
	//do bfs
	int cnt = 0;
	while(!q.empty()) {
		int front = q.front();
		q.pop();

		//increment count
		cnt++;

		for(auto nbr : adj[front]) {
			indegree[nbr]--;
			if(indegree[nbr] == 0)
				q.push(nbr);
		}
	}

	if(cnt == n)
		return false;
	else 
		return true;
}