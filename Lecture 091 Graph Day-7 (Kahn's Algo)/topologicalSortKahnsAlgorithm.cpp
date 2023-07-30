//https://www.codingninjas.com/codestudio/problems/topological-sort_982938
//Time and space complexity will be linear such as O(N+E) and O(N) respectively.

#include <bits/stdc++.h> 
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    //prepare adj list
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    //find all indegree
    vector<int> indegree(v);
    for(auto i: adj) {
        for(auto j: i.second) {
            indegree[j]++;
        }
    }

    //Push vertices with 0-indegree into queue
    queue<int>q;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //do bfs
    vector<int> ans;
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        //store in ans
        ans.push_back(frontNode);
        //update neighbour indegree
        for(auto neighbour: adj[frontNode]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }
    return ans;
}