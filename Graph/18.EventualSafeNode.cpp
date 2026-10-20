// 802. Find Eventual Safe States
// Solved
// Medium

// There is a directed graph of n nodes with each node labeled from 0 to n - 1. 
//   The graph is represented by a 0-indexed 2D integer array graph where graph[i] 
// is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe
// node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

class Solution {
public:
    bool dfs(int node, vector<int>& state, vector<vector<int>>& mat) {
        if (state[node] == 1) return true;  // Cycle detected
        if (state[node] == 2) return false; // Already safe

        state[node] = 1;

        for (auto it : mat[node]) {
            if (dfs(it, state, mat)) {
                return true;
            }
        }

        state[node] = 2;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> state(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!dfs(i, state, mat)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
