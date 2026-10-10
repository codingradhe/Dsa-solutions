// 994. Rotting Oranges
// Medium
// You are given an m x n grid where each cell can have 
// one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally
// adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must 
// elapse until no cell has a fresh orange. If this is
// impossible, return -1.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(),cnt = 0;
        vector<bool> vis(m*n,false);
        queue<int>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                if(mat[i][j] == 0){
                    vis[i*m+j] = 1;
                }
                else if(mat[i][j]==2){
                    q.push(i*m+j);
                    vis[i*m+j] = 1;
                }
                else cnt++;
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int ans = 0;
        while(!q.empty()){
            bool change = false;
            int size = q.size();
            for(int i = 0;i < size; i++){
                int x = q.front();
                q.pop();
                int row = x/m;
                int col = x%m;
                for(int j = 0; j < 4; j++){
                    int nrow = row + delrow[j];
                    int ncol = col + delcol[j];
                    if(nrow>= 0&&nrow<n&&ncol >= 0&&ncol < m&&vis[nrow*m+ncol] != 1&&mat[nrow][ncol] == 1) {
                        cnt--;
                        q.push(nrow*m+ncol);
                        vis[nrow*m+ncol] = true;
                        change = true;
                    }
                }
            }
            if(change) ans++;
        }
        if(cnt) return -1;
        return ans;
    }
};
