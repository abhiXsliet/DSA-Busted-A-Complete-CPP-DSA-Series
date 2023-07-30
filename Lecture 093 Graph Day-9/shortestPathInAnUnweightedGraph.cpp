//https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int, list<int>> adj;
	//prepare adj list
	for(int i=0; i<m; i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//do bfs
	vector<bool> visited(n);
	unordered_map<int, int>parent;
	queue<int>q;

	q.push(s);
	visited[s] = 1;
	parent[s] = -1;
	
	while(!q.empty()) {
		int frontNode = q.front();
		q.pop();

		for(auto neighbour: adj[frontNode]) {
			if(!visited[neighbour]) {
				visited[neighbour] = 1;
				parent[neighbour] = frontNode;
				q.push(neighbour);
			}
		}
	}

	//prepare shortest path using parent
	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);

	while(currentNode != s) {
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
