//Graph is a DS which is a combination of nodes and edges
//Edges direction determines the DIRECTED or UNDIRECTED graph

//NODE ->  Entity to store data
//EDGE -> Conecting nodes
//Degree -> No. of edges (directed or undirected) determines the Degree of that respective node
    //-> Indegree
    //-> Outdegree

//Weighted Graph  
//Path
//Cyclic Graph
//Acyclic Graph

//Graph implementation can be done by
//1. Adjacency Matrix
//2. Adjacency List

//Implementing graph by using 2.Adjacency List
#include<iostream>
#include<unordered_map>
#include<list>
template <typename T>

class graph {
    public:
        //T -> generaic type data
        std::unordered_map<T, std::list<T>> adj;

        void addEdges(T u, T v, bool direction) {
            //direction = 0-> undirected graph
            //direction = 1-> directed graph

            //create an edge form u to v
            adj[u].push_back(v);
            if(direction == 0) {
                adj[v].push_back(u);
            }
        }

        void printAdjList() {
            std::cout << "\nPrinting Nodes and their respective Edges " << std::endl;
            for(auto i: adj) {
                std::cout << i.first << " -> " ;
                for(auto j: i.second) {
                    std::cout << j << " ";
                }
                std::cout << std::endl;
            }
        }
};

int main() {
    int n;
    std::cout << "\nEnter the number of nodes => " ;
    std::cin >> n;

    int m;
    std::cout << "\nEnter the number of edges => ";
    std::cin >> m;

    graph<int> g; 
    // graph g //without any template
    
    std::cout << "\nEnter nodes and their respective connected edges (space separated)" << std::endl;
    for(int i=0; i<m; i++) {
        int u, v;
        std::cin >> u >> v;

        //creating an undirected graph
        g.addEdges(u, v, 0);
    }
    //printing graph
    g.printAdjList();
    


    std::cout << std::endl;
    return 0;
}