//  🖊️🖊️🖊️ access number of rows in 2D vector = v.size();
//  🖊️🖊️🖊️ access number of coloumn in 2D vector = v[0].size();
// gfg link of this problem --> https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
class Solution {
  public:
    vector<int>sortTwoArray(vector<int> &v1,vector<int> & v2){
        vector<int>ans;
        int n = v1.size(),m = v2.size();
        int i=0,j=0;
        while(i<n&&j<m){
            if(v1[i]==v2[j]){
                ans.push_back(v2[j]);
                ans.push_back(v1[i]);
                j++,i++;
            }
            else if(v1[i]>v2[j]){
                ans.push_back(v2[j]);
                j++;
            }
            else if(v1[i]<v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
        }
        while(i<n){
            ans.push_back(v1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(v2[j]);
            j++;
        }
        return ans;
    }
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        if(mat.empty()) return {};
        vector<int>ans = mat[0];
        for(int i = 1;i<mat.size();i++){
            ans = sortTwoArray(ans,mat[i]);
        }
        return ans;
    }
};
