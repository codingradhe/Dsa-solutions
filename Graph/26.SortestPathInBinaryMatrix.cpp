// 1091. Shortest Path in Binary Matrix
// Medium
// Given an n x n binary matrix grid, return the length of the shortest clear 
// path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) 
// to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they 
//   are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

 
class Solution {
public:
    bool isvalid(int row, int col, int n) {
        return row >= 0 && row < n &&
               col >= 0 && col < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int n = mat.size();

        if(mat[0][0] == 1 || mat[n-1][n-1] == 1)
            return -1;

        vector<int> delrow = {-1,-1,0,1,1,1,0,-1};
        vector<int> delcol = {0,1,1,1,0,-1,-1,-1};

        queue<pair<int,int>> q;

        q.push({0,0});
        mat[0][0] = 1;

        int dist = 1;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [row, col] = q.front();
                q.pop();

                if(row == n-1 && col == n-1)
                    return dist;

                for(int k = 0; k < 8; k++) {
                    int nrow = row + delrow[k];
                    int ncol = col + delcol[k];

                    if(isvalid(nrow,ncol,n) &&
                       mat[nrow][ncol] == 0) {

                        q.push({nrow,ncol});
                        mat[nrow][ncol] = 1;
                    }
                }
            }

            dist++;
        }

        return -1;
    }
};
