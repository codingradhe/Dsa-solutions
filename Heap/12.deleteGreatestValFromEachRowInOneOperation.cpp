// 2500. Delete Greatest Value in Each Row
// Easy
// You are given an m x n matrix grid consisting of positive integers.

// Perform the following operation until grid becomes empty:

// Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
// Add the maximum of deleted elements to the answer.
// Note that the number of columns decreases by one after each operation.

// Return the answer after performing the operations described above.
// // ✍️✍️ 
// 1.make vector of priority quueue of each row of matrix.
//   2.delete one eleemnt from each queue and add greaest from then to ans ;
// return ans 
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        vector<priority_queue<int>>q;
        for(int i = 0;i < grid.size();i++){
            priority_queue<int>tem(grid[i].begin(),grid[i].end()); 
            q.push_back(tem);
        }
        for(int i = 0;i < grid[0].size();i++){
            int sum = 0;
            for(int j = 0;j < grid.size();j++){
                sum = max(sum,q[j].top());
                q[j].pop();
            }
            ans += sum;
        }
        return ans;
    }
};

