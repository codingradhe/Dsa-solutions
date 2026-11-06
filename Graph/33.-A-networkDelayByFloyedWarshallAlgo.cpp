
// 743. Network Delay Time
// Solved
// Medium
// You are given a network of n nodes, labeled from 1 to n. You are also given times, 
// a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is 
// the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for 
// all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 class Solution {
public:
    void floyedWarshallAlgo(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][k] != 1e9 && mat[k][j] != 1e9) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
        return;
    }
    int networkDelayTime(vector<vector<int>>& edg, int n, int k) {
        int size = edg.size();
        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 1e9));
        for (auto it : edg) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v] = wt;
        }
        for (int i = 1; i <= n; i++) {
            mat[i][i] = 0;
        }
        floyedWarshallAlgo(mat);
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (mat[k][i] == 1e9)
                return -1;

            ans = max(ans, mat[k][i]);
        }

        return ans;
    }
};
