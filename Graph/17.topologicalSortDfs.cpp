// Topological Sort
// Solved
// Difficulty: MediumAccuracy: 56.52%Submissions: 375K+Points: 4Average Time: 15m
// Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and E 
// directed edges represented by a 2D array edges[][], where edges[i] = [u, v] denotes a
// directed edge from vertex u to vertex v, return a topological ordering of all the vertices.

// A topological ordering is a linear ordering of the vertices such that for every directed
// edge u -> v, vertex u appears before vertex v in the ordering.

// Note: As there are multiple Topological orders possible, you may return any of them.
//   If your returned Topological sort is correct then the output will be true else false.

//💕💕💕 use stack to store correct order of element
class Solution {
public:
    void dfs(int node, vector<int>& vis,
             vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        // Push only after visiting all neighbors
        st.push(node);
    }

    vector<int> topoSort(int v, vector<vector<int>>& edg) {
        vector<vector<int>> adj(v);

        for (auto& edge : edg) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> vis(v, 0);
        stack<int> st;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
