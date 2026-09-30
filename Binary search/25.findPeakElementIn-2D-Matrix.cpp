// 1901. Find a Peak Element II
// Medium
// A peak element in a 2D grid is an element that is strictly
// greater than all of its adjacent neighbors to the left, 
// right, top, and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent
// cells are equal, find any peak element mat[i][j] and 
// return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by
// an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in 
// O(m log(n)) or O(n log(m)) time.

  
class Solution {
public:
    int findmax(vector<vector<int>>& mat,int mid){
        int ans = -1,maxi = INT_MIN;
        for(int i = 0; i < mat.size();i++){
            if(mat[i][mid] > maxi){
                maxi = mat[i][mid];
                ans = i;
            }
        }
        return ans;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int>ans;
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1,mid;
        while(low <= high){
            mid = low + (high - low)/2;
            int row = findmax(mat,mid);
            int left = mid - 1 >=0 ? mat[row][mid -1] : -1;
            int right = mid + 1 <= m -1 ? mat[row][mid +1] : -1;
            int x = mat[row][mid];
            if(x > left && x > right) {
                ans = {row,mid};
                break;
            }
            else if(x < left) high = mid - 1;
            else low = mid + 1; 
        }
        return ans;
    }
};
