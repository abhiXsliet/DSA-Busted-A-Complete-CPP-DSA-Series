//https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151

#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
using namespace std;

void dfs(int node, unordered_map<int, bool>& vis, unordered_map<int, 
			list<int>>& adj, stack<int>& topo) {
	
	vis[node] = true;

	for(int nbr : adj[node]) {
		if(!vis[nbr]) {
			dfs(nbr, vis, adj, topo);
		}
	}
	topo.push(node);
}

void revDfs(int node, unordered_map<int, bool>& vis, 
			unordered_map<int, list<int>>& adj) {
	
	vis[node] = true;
	
	for(auto nbr : adj[node]) {
		if(!vis[nbr]) {
			revDfs(nbr, vis, adj);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//prepare adjacency list
	unordered_map<int, list<int> > adj;
	for(int i=0; i<edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
	}

	//topological sort
	stack<int> topo;
	unordered_map<int, bool> vis;

	for(int i=0; i<v; i++) {
		if(!vis[i]) {
			dfs(i, vis, adj, topo);
		}
	}

	//create Transpose of a graph
	unordered_map<int, list<int>> transpose;

	for(int i=0; i<v; i++) {
		vis[i] = false;

		for(auto nbr : adj[i]) {
			transpose[nbr].push_back(i);
		}
	}

	//dfs call by using stack ordering
	int count = 0;
	while(!topo.empty()) {
		int top = topo.top();
		topo.pop();

		if(!vis[top]) {
			count++;
			revDfs(top, vis, transpose);
		}
	}

	return count;
}