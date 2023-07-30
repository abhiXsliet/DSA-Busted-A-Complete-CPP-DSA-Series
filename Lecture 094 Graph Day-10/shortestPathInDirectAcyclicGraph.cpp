//Finding the shortest path in a directed graph
//Time and space complexity will be linear O(N+E)

#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
        unordered_map<int, list<pair<int, int> > > adj;
        void addEdge(int u, int v, int weight) {
            pair<int, int>p = make_pair(v, weight);
            adj[u].push_back(p);
        }

        void printAdj() {
            for(auto i: adj) {
                cout << i.first << " -> ";
                for(auto j: i.second) {
                    cout << "(" << j.first << "," << j.second << "), " ;
                }cout << endl;
            }cout << endl;
        }

        void dfs(int node, unordered_map<int, bool>& visited, stack<int>& topo) {
            visited[node] = 1;
            for(auto neighbour: adj[node]) {
                if(!visited[neighbour.first]) {
                    dfs(neighbour.first, visited, topo);
                }
            }
            topo.push(node);
        }

        void getShortestPath(int src, vector<int>& dist, stack<int>& topo) {
            
            dist[src] = 0;
            
            while(!topo.empty()) {
                int top = topo.top();
                topo.pop();

                if(dist[top] != INT_MAX) {
                    for(auto neigh: adj[top]) {
                        if(dist[top] + neigh.second < dist[neigh.first]) {
                            dist[neigh.first] = dist[top] + neigh.second;
                        }
                    }   
                }
            }
        }
};

int main() {

    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    int n = 6; //where n is the no. of vertices

    //topological sort
    unordered_map<int, bool>visited;
    stack<int>s;

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int>dist(n, INT_MAX);

    g.getShortestPath(src, dist, s);
    cout << "Shortest Path will be => " ;
    for(int i=0; i<dist.size(); i++) {
        cout << dist[i] << " ";
    }cout << endl;
    

    
    cout << endl;
    return 0;
}