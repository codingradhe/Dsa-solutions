// 200. Number of Islands
// Medium
// Given an m x n 2D binary grid grid which represents
// a map of '1's (land) and '0's (water), return the 
//   number of islands.

// An island is surrounded by water and is formed by
// connecting adjacent lands horizontally or vertically.
//   You may assume all four edges of the grid are
// all surrounded by water.
class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> adj(m * n);
        vector<int> vis(m * n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(i > 0){
                    if(grid[i -1][j] == '1') adj[cnt].push_back(cnt - m);
                }
                if(i < n -1){
                    if(grid[i+1][j] =='1') adj[cnt].push_back(cnt + m);
                }
                if(j > 0){
                if(grid[i][j-1]=='1') adj[cnt].push_back(cnt -1);
                }
                if(j < m -1){
                    if(grid[i][j+1]=='1') adj[cnt].push_back(cnt +1);
                }
                cnt++;
            }
        }
        int ans = 0;
        int size = m*n;
        for(int i = 0; i < size;i++){
            if(grid[i/m][i%m] == '1'&&!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};
