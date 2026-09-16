// 2558. Take Gifts From the Richest Pile
// Easy
// You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

// Choose the pile with the maximum number of gifts.
// If there is more than one pile with the maximum number of gifts, choose any.
// Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.
// Return the number of gifts remaining after k seconds.
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i = 0;i < nums.size();i++){
            q.push(nums[i]);
        }
        while(!q.empty()){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            ans.push_back(y);
            ans.push_back(x);
        }
        return ans;
    }
};
