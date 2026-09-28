// 707. Find row with maximum 1's
// Given a non-empty grid mat consisting of only 0s
// and 1s, where all the rows are sorted in ascending
// order, find the index of the row with the maximum number
// of ones.

// If two rows have the same number of ones, consider
// the one with a smaller index. If no 1 exists in the
// matrix, return -1.
// problem link -->>   https://takeuforward.org/practice/dsa/find-row-with-maximum-1's?tab=problem
  class Solution {
  public:   
  int rowWithMax1s(vector < vector < int >> & mat){
      int n = mat.size(),m = mat[0].size();
      int low = 0,high = m - 1 , mid;
      int ans = -1;
      while(low <= high){
          mid = low + (high - low)/2;
          bool get = false;
          for(int i = 0;i < n; i++){
              if(mat[i][mid] == 1){
                  get = true;
                  ans = i;
                  break;
              }
          }
          if(get)  high = mid -1;
          else low = mid + 1; 
      }
      return ans;  }
};
