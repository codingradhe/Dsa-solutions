// 1631. Path With Minimum Effort
// Medium
// You are a hiker preparing for an upcoming hike. You are given heights,
//   a 2D array of size rows x columns, where heights[row][col] represents the
// height of cell (row, col). You are situated in the top-left cell, (0, 0), and you 
// hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move
// up, down, left, or right, and you wish to find a route that requires the minimum effort.
// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 class Solution {
public:
    bool isvalid(vector<vector<int>>& mat,int row , int col) {
        int n = mat.size();
        int m = mat[0].size();
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    int minimumEffortPath(vector<vector<int>>& mat) {
        int n =  mat.size();
        int m = mat[0].size();
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(m*n ,0);
        pq.push({0,0});
        int ans = INT_MAX;
        while(!pq.empty()){
            auto ptr = pq.top();
            pq.pop();
            int node = ptr.second;
            if(vis[node]) continue;
            vis[node] = 1;
            int row = node / m;
            int col = node % m;
            int mh = ptr.first;
            if(row == n - 1 && col == m - 1) return  mh;
            vis[row * m + col] = 1;
            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(isvalid(mat,nrow,ncol) && !vis[nrow*m + ncol]){
                    int parent = mat[row][col];
                    int child = mat[nrow][ncol];
                    int affort = max(mh,abs(parent - child));
                    pq.push({affort,nrow * m + ncol});
                }
            }
        }
        return ans;
    }
};
