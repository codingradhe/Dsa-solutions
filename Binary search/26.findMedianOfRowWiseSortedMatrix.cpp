// Median in a Row-Wise Sorted Matrix
// Solved
// Given a row-wise sorted matrix mat[][] of size n x m,
// where the number of rows and columns is always odd. 
// Return the median of the matrix.
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        vector<int>ans;
        int n = mat.size(),m = mat[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0; j < m; j++){
                ans.push_back(mat[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        int size = ans.size();
        return ans[(size/2)];
        
    }
};
