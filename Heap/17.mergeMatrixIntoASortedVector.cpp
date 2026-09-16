// Merge k Sorted Arrays
// Solved
// Given a 2D matrix mat[][] of size n x m. Each row in
// the matrix is sorted in non-decreasing order, merge all the
// rows and return a single sorted array that contains all
// the elements of the matrix.
//   // gfg link -->> https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
  class Solution {
	public:
	void merge(vector<int>&ans, vector<vector<int>>&mat, int k)
{		
        if (k == mat.size())
			return ;
		int i = 0, j = 0;
		vector<int>tem;
		while (i < ans.size() && j < mat[k].size()) {
			if (ans[i] <= mat[k][j]) {
				tem.push_back(ans[i]);
				i++;
			}
			else {
				tem.push_back(mat[k][j]);
				j++;
			}
		}
		while(i < ans.size()){
		    tem.push_back(ans[i]);
		    i++;
		}
		while(j < mat[0].size()){
		    tem.push_back(mat[k][j]);
		    j++;
		}
		ans = tem;
		tem.clear();
		merge(ans,mat,k+1);
		return;
	}
	vector<int> mergeArrays(vector<vector<int>> &mat) {
		vector<int>ans;
		merge(ans,mat,0);
		return ans;
		
	}
};


