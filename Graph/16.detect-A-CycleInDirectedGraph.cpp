// 192. Detect a cycle in a directed graph
// Companies
// Given a directed graph with V vertices labeled from 0 to 
// V-1. The graph is represented using an adjacency list 
// where adj[i] lists all nodes connecte

// 😭😭 it is not similar to undirected you need to make two visited

class Solution{
public:
    bool check(int  node,vector<int> &vis,vector<int>&pathvis,vector<int> adj[]){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]&&check(it,vis,pathvis,adj)) return true;
            else if(pathvis[it]) return true;
        }
      // free pathvis to check for next call 
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(int N, vector<int> adj[]) {
        int  n = N;
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        for(int i =0; i < n; i++){
            if(!vis[i]&&check(i,vis,pathvis,adj)) return true;
        }
        return false;
    }
};
