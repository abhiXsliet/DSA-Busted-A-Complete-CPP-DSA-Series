//https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

void prepareAdj(vector<vector<int>>& edges, int m, unordered_map<int, list<int>>& adjList) {
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

//Cycle Detection through BFS Traversal
bool isCyclicBFS(int src, unordered_map<int ,bool>& visited, unordered_map<int, 
            list<int>>& adjList) {

    unordered_map<int, int> parent;
    queue<int>q;

    parent[src] = -1;
    visited[src] = 1;
    q.push(src);

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto i : adjList[frontNode]) {
            if(i != parent[frontNode] && visited[i] == true) {
                return true;
            } 
            else if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }
    return false;
}

//Cycle Detection through DFS traversal
bool isCyclicDFS(int src, int parent, unordered_map<int, bool> &visited, unordered_map<int, 
                list<int>>&adjList) {
    
    visited[src] = 1;

    //recursive call for each adjacent node
    for(auto i: adjList[src]) {
        if(!visited[i]) {
            bool cycleDetected = isCyclicDFS(i, src, visited, adjList);
            if(cycleDetected)
                return true;
        }
        else if(i != parent) {
            //cycle Detected 
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>>adjList;
    unordered_map<int, bool>visited;

    //prepare adjacency list
    prepareAdj(edges, m, adjList);

    //traverse for each component
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            
            // bool ans = isCyclicBFS(i, visited, adjList);
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if(ans == 1) {
                return "Yes";
            }
        }
    }
    return "No";
}
