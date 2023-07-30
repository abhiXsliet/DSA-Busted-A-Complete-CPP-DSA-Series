//https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769
//Time complexity will be O(MlogN) and space complexity will be linear- O(N) where m = no. of edges and n = no. of vertices of graph


#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

void makeSet(vector<int>& parent, vector<int>& rank, int n) {
    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int>& parent, int node) {
    //base case
    if(parent[node] == node) {
        return node;
    }

    //recursive call -> path compression
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    //sort a/c weight of edges in ascending
    sort(edges.begin(), edges.end(), cmp);

    int wtCount = 0;

    for(int i=0; i<edges.size(); i++) {

        int edgeWt = edges[i][2];

        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if(u != v) {
            wtCount += edgeWt;
            unionSet(u, v, parent, rank);
        }
    }
    return wtCount;
}

