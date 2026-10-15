// 130. Surrounded Regions
// Medium
// You are given an m x n matrix board containing letters 
// 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally
// or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: A region is surrounded if none of the 'O' cells 
//   in that region are on the edge of the board. Such regions 
// are completely enclosed by 'X' cells.
// To capture a surrounded region, replace all 'O's with 'X's 
  
//   in-place within the original board. You do not need to
// return anything.

// ♥️♥️ travesre all adjecent 'O" at one time when enter in recusive call 


class Solution {
public:
    bool check(int node,vector<int>&vis,vector<vector<char>>&mat,vector<int>&delrow,vector<int>&delcol,vector<int>&set){
        int n = mat.size(),m = mat[0].size();
        int row = node/m , col = node%m;
        bool ans = true;
        vis[node] = 1;
        set.push_back(node);
        if(row == 0|| row == n-1||col == 0|| col == m -1) ans = false;
        for(int i = 0; i < 4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0&& nrow < n&&ncol >= 0&& ncol <m && mat[nrow][ncol] == 'O'&&vis[nrow*m+ncol]== 0){
                if(!check(nrow*m +ncol,vis,mat,delrow,delcol,set)) ans = false;
            }
        }
        return ans;
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>vis(m*n ,0);
        vector<int>delrow={-1,0,1,0};
        vector<int>delcol ={0,1,0,-1};
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 'X') vis[i*m + j] = 1;
                else if(mat[i][j] == 'O'&&!vis[i*m+j]){
                    vector<int> set;
                    int x = i*m+j;
                    if(check(x,vis,mat,delrow,delcol,set)){
                        for(int k = 0;k < set.size();k++){
                            mat[set[k]/m][set[k]%m] = 'X';
                        }
                    }
                }
            }
        }
        return ;
    }
};
