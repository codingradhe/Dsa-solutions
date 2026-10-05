// 181. Traversal Techniques
// Given an undirected connected graph with V vertices
// numbered from 0 to V-1, the task is to implement 
// both Depth First Search (DFS) and Breadth First Search
// (BFS) traversals starting from the 0th vertex.

// The graph is represented using an array/vector of edges
// , where each element is a pair [u, v] indicating an undirected
// edge between vertex u and vertex v.
class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ans);
            }
        }
        return;
    }
    vector<int> dfsOfGraph(int n, vector<vector<int>> edges) {
        vector<int>ans;
        vector<vector<int>> adj(n);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);   // undirected graph
        }
        vector<int>vis(n,0);
        dfs(0,adj,vis,ans);
        return ans;
    }
    
    vector<int> bfsOfGraph(int n, vector<vector<int>> edges) {
        vector<int>ans;
        vector<vector<int>> adj(n);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);   // undirected graph
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto it: adj[x]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return ans;
    }
};
