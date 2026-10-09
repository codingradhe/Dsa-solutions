// 1020. Number of Enclaves
// Medium
// You are given an m x n binary matrix grid, where 0 represents 
// a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another 
// adjacent (4-directionally) land cell or walking off the 
// boundary of the grid.

// Return the number of land cells in grid for which we cannot 
// walk off the boundary of the grid in any number of moves.

//  ♥️♥️♥️🖊️  if there is one at boundary  or anywhere i will move in all direction
// if there is any side 1 wil be found 
// otherwise if there is 0 then i will move only in boundary direction 

class Solution {
public:
    bool isvalid(int row,int col,vector<vector<int>>&mat){
        int n = mat.size(), m = mat[0].size();
        if(row >=0&&row<n&& col >= 0&& col < m) return true;
        return false;
    }
    void dfs(int row,int col,vector<int>&delrow,vector<int>&delcol,vector<vector<int>>&mat){
        int n = mat.size(),m = mat[0].size();
        int curr = mat[row][col];
        mat[row][col] = -1;
        for(int i = 0;i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(isvalid(nrow,ncol,mat)&& curr == 1&&mat[nrow][ncol] != -1&&mat[nrow][ncol] == 1){
                dfs(nrow,ncol,delrow,delcol,mat);
            }
            else if(isvalid(nrow,ncol,mat)&& mat[nrow][ncol] != -1){
                if(nrow == 0|| nrow == n -1) {
                    dfs(nrow,ncol,delrow,delcol,mat);
                }
                else if(ncol == 0 ||ncol == m - 1){
                    dfs(nrow,ncol,delrow,delcol,mat);
                }
            }
        }
        return ;
    }
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        dfs(0,0,delrow,delcol,mat);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};
