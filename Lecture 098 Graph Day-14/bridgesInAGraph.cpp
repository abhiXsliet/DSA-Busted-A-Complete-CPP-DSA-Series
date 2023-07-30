//https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026
//Time and Space complexity will be O(V+E) where V = no. of vertices and E = no. of edges of the graph

#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int>& low, 
        vector<int>& disc, unordered_map<int, bool>& vis,
        unordered_map<int, list<int>>& adj, vector<vector<int>>& result ) {

    vis[node] = true;
    disc[node] = low[node] = timer++;

    for(auto neighbour: adj[node]) {
        if(neighbour == parent) {
            continue;
        }
        else if(!vis[neighbour]) {
            dfs(neighbour, node, timer, low, disc, vis, adj, result);
            low[node] = min(low[node], low[neighbour]);

            //check edge is a bridge?
            if(low[neighbour] > disc[node]) {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else {
            //Back Edge -> neighbour!=parent && visited[neighbour] == true
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    //prepare adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //intialise all data structures
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> visited;

    int parent = -1;
    int timer = 0;

    vector<vector<int>> result;

    //do dfs
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            dfs(i, parent, timer, low, disc, visited, adj, result);
        }
    }

    return result;
}