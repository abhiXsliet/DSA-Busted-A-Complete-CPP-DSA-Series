//https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002

#include <bits/stdc++.h> 
using namespace std;

//Time and Space complexity will be O(N+E) where N = vertex and E = Edges

void bfs(unordered_map<int, set<int>>& adjList, unordered_map<int, bool>& visited, 
        vector<int>& ans, int node) {

    queue<int>q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);
        
        //Traverse all the neighbours of frontNode
        for(auto i: adjList[frontNode]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void prepareAdj(unordered_map<int, set<int>>& adjList, 
                vector<pair<int, int>>& edges) {
    
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    vector<int> ans;

    prepareAdj(adjList, edges);

    //Traverse all the components of a graph
    for(int i=0; i<vertex; i++) {
        if(!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}