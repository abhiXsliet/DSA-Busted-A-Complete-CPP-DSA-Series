//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

void prepareAdj(vector<vector<int>>& edges, 
				unordered_map<int, list<int>> &adjList) {
	
	for(int i=0; i<edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];

		adjList[u].push_back(v);
	}
}

bool isCyclicDetect(int node, unordered_map<int, bool>& visited, 
			unordered_map<int, bool>& dfsVisited, unordered_map<int, list<int>>& adjList) {
	
	visited[node] = true;
	dfsVisited[node] = true;

	for(auto neighbour: adjList[node]) {
		if(!visited[neighbour]) {
			bool detected = isCyclicDetect(neighbour, visited, dfsVisited, adjList);
			if(detected)
				return true;
		}
		else if(dfsVisited[neighbour]) {

			//if both visited and dfsVisited is true means cycle present
			return true;
		}
	}

	dfsVisited[node] = false;
	return false;
}