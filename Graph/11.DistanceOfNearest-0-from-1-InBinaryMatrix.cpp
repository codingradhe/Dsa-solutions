// 542. 01 Matrix
// Medium
// Given an m x n binary matrix mat, return the distance
// of the nearest 0 for each cell.

// The distance between two cells sharing a common edge 
// is 1.

// brute force solution
class Solution {
public:
    int find(int node,vector<vector<int>>& mat,vector<int>&delrow,vector<int>&delcol){
        int n = mat.size(), m = mat[0].size();
        vector<int>vis(m*n,0);
        queue<pair<int,int>>q;
        q.push({node,0});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto p = q.front();
                q.pop();
                int row = p.first/m,col = p.first%m;
                if(mat[row][col] == 0) return p.second;
                vis[p.first] = 1;
                for(int j = 0; j < 4; j++){
                    int nrow = row + delrow[j];
                    int ncol = col + delcol[j];
                    if(nrow >= 0 && nrow < n&& ncol >= 0&& ncol < m && !vis[nrow*m + ncol]){
                        q.push({nrow*m + ncol,p.second +1});
                    }
                }
            }
        }
        return 0;
    }

// ♥️♥️♥️ best approach to use bfs traversal 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> delrow{-1,0,1,0};
        vector<int> delcol{0,1,0,-1};
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = find(i*m + j,mat,delrow,delcol);
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool check(int row,int col,vector<vector<int>>& mat){
        int n = mat.size(), m = mat[0].size();
        if(row >= 0&&row < n&& col >= 0&& col < m) return true;
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>vis(n*m,0);
        queue<pair<int,pair<int,int>>>q;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    vis[i*m +j] = 1;
                    q.push({1,{i,j}});
                }
            }
        }
        vector<int>delrow ={-1,0,1,0};
        vector<int>delcol ={0,1,0,-1};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size;i++){
                auto it = q.front();
                q.pop();
                int row = it.second.first;
                int col = it.second.second;
                int d = it.first;
                for(int i = 0; i< 4;i++){
                   int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(check(nrow,ncol,mat)&&vis[nrow*m+ncol] ==0){
                        mat[nrow][ncol] = d;
                        q.push({d+1,{nrow,ncol}});
                        vis[nrow*m+ncol] = 1;
                    }
                }
            }
        }
        return mat;
    }
};
