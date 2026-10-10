// 1971. Find if Path Exists in Graph
// Easy
// There is a bi-directional graph with n vertices, where each vertex 
// is labeled from 0 to n - 1 (inclusive). The edges in the graph are 
// represented as a 2D integer array edges, where each edges[i] = 
// [ui, vi] denotes a bi-directional edge between vertex ui and vertex 
// vi. Every vertex pair is connected by at most one edge, and no 
// vertex has an edge to itself.

// You want to determine if there is a valid path that exists from vertex
// source to vertex destination.

// Given edges and the integers n, source, and destination, 
// return true if there is a valid path from source to destination,
//   or false otherwise.

// ♥️♥️♥️🫂 simple start traversal form source and if you reached
// till destination then there is path or not ?

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edg, int s, int d) {
        if(s == d) return true;
        vector<vector<int>>adj(n);
        for(int i = 0;i < edg.size(); i++){
            int u = edg[i][0];
            int v = edg[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(s);
        vis[s] = 1;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(vis[x]!=0){
                for(auto it : adj[x]){
                    if(it == d) return true;
                    if(vis[it] == 0){
                        vis[it]  = 1;
                        q.push(it);
                    }
                }
            }
        }
        return false;
    }
};
