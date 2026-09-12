// 1337. The K Weakest Rows in a Matrix
// Easy

// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

// A row i is weaker than a row j if one of the following is true:

// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
//  leetcode link ->>  https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/?envType=problem-list-v2&envId=heap-priority-queue
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans(k);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i = 0; i < mat.size();i++){
            int cnt = 0;
            for(int j = 0;j < mat[0].size();j++){
                if(mat[i][j] == 1)  cnt++;
            }
            q.push({cnt,i});
        }
        for(int i = 0;i < k;i++){
            auto it = q.top();
            q.pop();
            ans[i] = it.second;
        }
        return ans;
    }
};
