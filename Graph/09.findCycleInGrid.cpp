// 1559. Detect Cycles in 2D Grid
// Medium
// Given a 2D array of characters grid of size m x n,
// you need to find if there exists any cycle consisting
// of the same value in grid.

// A cycle is a path of length 4 or more in the grid 
// that starts and ends at the same cell. From a given
// cell, you can move to one of the cells adjacent to 
// it - in one of the four directions (up, down, left, 
// or right), if it has the same value of the current 
// cell.

// Also, you cannot move to the cell that you visited in
// your last move. For example, the cycle 
//   (1, 1) -> (1, 2) -> (1, 1) is invalid because from
// (1, 2) we visited (1, 1) which was the last visited
// cell.

// Return true if any cycle of the same value exists
// in grid, otherwise, return false.

// find visited  have same character as initial and not have revious 
class Solution {
public:
    bool dfs(int node ,int parent,vector<vector<char>>& mat,vector<int>&delrow,vector<int>&delcol,vector<int>&vis){
        int n = mat.size(),m = mat[0].size();
        vis[node] = 1;
        int row = node/m,col = node%m;
        for(int i = 0; i < 4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0&& nrow < n&& ncol >= 0 && ncol < m){
                if(vis[nrow*m + ncol] &&mat[nrow][ncol] == mat[row][col]&& nrow*m + ncol != parent) return true;
                if(mat[nrow][ncol] == mat[row][col] && !vis[nrow*m + ncol]&& dfs(nrow*m+ ncol,node,mat,delrow,delcol,vis)) return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& mat) {
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        int  n = mat.size(), m = mat[0].size();
        vector<int>vis(m*n , 0);
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i*m + j]){
                    int x = i*m + j;
                    if(dfs(x,-1,mat,delrow,delcol,vis)) return true;
                }
            }
        }
        return false;
    }
};
