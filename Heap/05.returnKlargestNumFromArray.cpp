// 2099. Find Subsequence of Length K With the Largest Sum
// Easy
// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

// Return any such subsequence as an integer array of length k.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// leetcode link -->>   https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/?envType=problem-list-v2&envId=heap-priority-queue
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        map<int,int>mp;
        priority_queue<pair<int,int>>q;
        for(int i = 0;i < nums.size();i++){
            q.push({nums[i],i});
        }
        for(int i = 0;i < k;i++){
            auto it = q.top();
            q.pop();
            mp[it.second ] = it.first;
        }
        nums.clear();
        for(auto it:mp) nums.push_back(it.second);

        return nums;
    }
};
