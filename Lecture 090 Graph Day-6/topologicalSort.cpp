//https://www.codingninjas.com/codestudio/problems/topological-sort_982938
//Time and Space complexity both will be linear such that O(N+V) and O(N) respectively

#include <bits/stdc++.h> 
using namespace std;

void topoSort(int node, vector<bool>& visited, 
            unordered_map<int, list<int>>& adj, stack<int>&s) {
    
    visited[node] = 1;

    for(auto neighbour: adj[node]) {
        if(!visited[neighbour]) {
            topoSort(neighbour, visited, adj, s);
        }
    }

    //push into stack on returning from RC
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    unordered_map<int, list<int>> adj;
    //prepare adjacency list
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int>s;

    //call dfs topology sort util function for each component DAG
    for(int i=0; i<v; i++){
        if(!visited[i]) {
            topoSort(i, visited, adj, s);
        }
    }

    vector<int>ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}