// 240. Search a 2D Matrix II
// Medium
// Write an efficient algorithm that searches for 
// a value target in an m x n integer matrix matrix.
//   This matrix has the following properties:

// Integers in each row are sorted in ascending from
// left to right.
// Integers in each column are sorted in ascending
// from top to bottom.

// ♥️♥️♥️🎊 you can start form right top or bottom left otherwise logic does not work

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int row = 0, mid ,col = m -1;
        while(row < n && col >=0){
            int x = mat[row][col];
            if(x == target) return true;
            else if(x > target ) col--;
            else row++;
        }
        return false;
    }
};
