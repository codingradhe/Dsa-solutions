// Min Cost to Connect Ropes
// Solved
// Given an array, arr[] of rope lengths, connect all ropes
// into a single rope with the minimum total cost. The cost
// to connect two ropes is the sum of their lengths. Return
//   the minimum possible cost.

//  gfg link -->> https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
//   class Solution {
  public:
    int minCost(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i = 0;i < nums.size();i++){
            q.push(nums[i]);
        }
        int ans = 0;
        while(q.size()>1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            ans += (x+y);
            q.push(x+y);
        }
        return ans;
    }
};
