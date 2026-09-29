// 74. Search a 2D Matrix
// Medium
// You are given an m x n integer matrix matrix with 
// the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the
// last integer of the previous row.
// Given an integer target, return true if target 
// is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) 
//   time complexity.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
         int m = mat.size(), n = mat[0].size();
        int low = 0, mid , high = m * n - 1;
        while(low <= high){
            mid = low + ( high - low ) / 2;
            int x = mat[mid / n][mid % n];
            if(x == target ) return true;
            else if( x < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
