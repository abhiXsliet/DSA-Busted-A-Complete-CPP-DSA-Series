//https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633
//Time complexity will be O(n^2) and the space complexity will be linear O(m+n) where m = no. of edges and n = no. of vertices of graph

#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //create adjacency list
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i=0; i<m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //Initialise all data structures
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, 0);
    vector<int> parent(n+1, -1);

    //processing
    int src = 1;
    key[src] = 0;
    parent[src] = -1;

    for(int i=1; i<n; i++) {
        int mini = INT_MAX;
        int u;
        for(int v=1; v<=n; v++) {
            //find the minimum
            if(mst[v] == false && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        //mark min as true;
        mst[u] = true;

        //find adjacent nodes of min
        for(auto i: adj[u]) {
            int v = i.first;
            int w = i.second;

            if(mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int> > result;
    for(int i=2; i<=n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
