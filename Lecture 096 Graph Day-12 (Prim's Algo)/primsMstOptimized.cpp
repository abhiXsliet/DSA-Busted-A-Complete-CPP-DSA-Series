//https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633
//Time complexity will be O(MlogN) and space complexity will be linear- O(M+N) where m = no. of edges and n = no. of vertices of graph

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
    vector<int> dist(n+1, INT_MAX);
    vector<bool> mst(n+1, 0);
    vector<int> parent(n+1, -1);

    //processing
    int src = 1;
    dist[src] = 0;
    parent[src] = -1;

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        int topNode = pq.top().second;
        int topDist = pq.top().first;
        pq.pop();

        //mark min as true;
        mst[topNode] = true;

        //find adjacent nodes of min
        for(auto i: adj[topNode]) {
            int v = i.first;
            int w = i.second;

            if(mst[v] == false && w < dist[v]) {
                parent[v] = topNode;
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }

    vector<pair<pair<int, int>, int> > result;
    for(int i=2; i<=n; i++) {
        result.push_back({{parent[i], i}, dist[i]});
    }
    return result;
}
