//https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469
//Time Complexity will be O(ElogV) where E = edges and V = vertices
//Space Complexity will be O(N+E) -> linear

#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //create a adjacency list
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i=0; i<edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    //create a distance array
    vector<int>dist(vertices, INT_MAX);

    //creation of set on basis (distance, node)
    set<pair<int, int>> st;

    //initialize distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty()) {
        //fetch top record
        auto top = *(st.begin());

        int nodeDistance  = top.first;
        int topNode = top.second;

        //remove record 
        st.erase(st.begin());

        //traverse on each neighbours 
        for(auto neighbour: adj[topNode]) {
            if(nodeDistance + neighbour.second < dist[neighbour.first]) {
                //find record 
                auto record = st.find( make_pair(dist[neighbour.first], neighbour.first) );
                //if record found then erase it
                if(record != st.end()) {
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;

                //insert the entry into set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
