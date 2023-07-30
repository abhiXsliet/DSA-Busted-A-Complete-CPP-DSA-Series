//https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462

#include<bits/stdc++.h>
using namespace std;

//Time and Space complexity will be linear

void prepareAdj(unordered_map<int, list<int>>& adjList, vector<vector<int>>& edges) {
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, 
        vector<int>& component, int node) {
    
    component.push_back(node);
    visited[node] = 1;

    for(auto i: adjList[node]) {
        if(!visited[i]) {
            dfs(adjList, visited, component, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    //prepare adjacency list
    prepareAdj(adjList, edges);

    //Traverse all the components of the graph
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            vector<int>component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}