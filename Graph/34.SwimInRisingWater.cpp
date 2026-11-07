// 778. Swim in Rising Water
// Hard
// You are given an n x n integer matrix grid where each value grid[i][j] 
// represents the elevation at that point (i, j).

// It starts raining, and water gradually rises over time. At time t, the water 
// level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

// You can swim from a square to another 4-directionally adjacent square if and only 
// if the elevation of both squares individually are at most t. You can swim infinite 
// distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// Return the minimum time until you can reach the bottom right square (n - 1, n - 1) 
//   if you start at the top left square (0, 0).

 class Solution {
public:
    bool isvalid(int row, int col, vector<vector<int>>& mat) {
        int n = mat.size();
        return (row >= 0 && row < n && col >= 0 && col < n);
    }
    int swimInWater(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> vis(n * n, 0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};

        q.push({mat[0][0], 0});

        while (!q.empty()) {
            auto ptr = q.top();
            q.pop();

            int level = ptr.first;
            int node = ptr.second;

            if (vis[node]) continue;

            vis[node] = 1;

            int row = node / n;
            int col = node % n;
            if (row == n - 1 && col == n - 1) {
                return level;
            }
            for (int j = 0; j < 4; j++) {
                int nrow = row + delrow[j];
                int ncol = col + delcol[j];
                if (isvalid(nrow, ncol, mat) &&
                    !vis[nrow * n + ncol]) {
                    int newlevel = max(level, mat[nrow][ncol]);
                    q.push({newlevel, nrow * n + ncol});
                }
            }
        }
        return -1;
    }
};
