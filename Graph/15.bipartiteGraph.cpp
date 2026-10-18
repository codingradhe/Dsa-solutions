// 785. Is Graph Bipartite?
// Medium
// There is an undirected graph with n nodes, where 
// each node is numbered between 0 and n - 1. You 
//   are given a 2D array graph, where graph[u] is 
// an array of nodes that node u is adjacent to. More 
// formally, for each v in graph[u], there is an undirected 
// edge between node u and node v. The graph has the 
// following properties:

// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain 
// duplicate values).
// If v is in graph[u], then u is in graph[v] 
// (the graph is undirected).
// The graph may not be connected, meaning there may 
// be two nodes u and v such that there is no path 
// between them.
// A graph is bipartite if the nodes can be 
// partitioned into two independent sets A and B such 
// that every edge in the graph connects a node in 
// set A and a node in set B.

// Return true if and only if it is bipartite.

// ♥️♥️ a bipartite graph is that in which  there is a cycle wiht odd number of ode 

class Solution {
public:
    bool isBipartite(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> vis(n, -1);

        for (int i = 0; i < n; i++) {
            if (vis[i] != -1) continue;

            queue<int> q;
            q.push(i);
            vis[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto it : mat[node]) {
                    if (vis[it] == -1) {
                        vis[it] = !vis[node];
                        q.push(it);
                    }
                    else if (vis[it] == vis[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
