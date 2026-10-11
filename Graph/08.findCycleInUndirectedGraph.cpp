// Undirected Graph Cycle
// Solved
// Given an undirected graph with V vertices and E edges
// , represented as a 2D vector edges[][], where each 
// entry edges[i] = [u, v] denotes an edge between vertices
// u and v, determine whether the graph contains a cycle 
// or not.

// Note: The graph can have multiple component.

// ♥️♥️ you can use both dfs and bfs 

class Solution {
public:
    bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for (auto it : adj[node]) {

            if (!vis[it]) {
                if (dfs(it, node, adj, vis))
                    return true;
            }
            else if (it != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int n, vector<vector<int>>& edg) {
        vector<vector<int>> adj(n);

        for (auto it : edg) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }

        return false;
    }
};
