// 213. House Robber II
// Solved
// Medium
// You are a professional robber planning to rob houses along a street. Each house has a certain
// amount of money stashed. All houses at this place are arranged in a circle. That means the first
// house is the neighbor of the last one. Meanwhile, adjacent houses have a security system
// connected, and it will automatically contact the police if two adjacent houses were broken
// into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum 
// amount of money you can rob tonight without alerting the police.

 

class Solution {
public:
    int find(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0] , nums[1]);
        int pre = nums[2] + nums[0] , spre = nums[1] , tpre = nums[0];
        for(int i = 3; i < n ; i++){
            int curr = max(spre , tpre) + nums[i];
            tpre = spre ;
            spre = pre ;
            pre = curr;
        }
        return max(pre , spre);
    }
// original function
// ❤️💕💕😂 just solve using function house robber 2 __>> use login you can not take both first and last in one time becasue 
// they are adjacent element or house 
    int rob(vector<int>& nums) {
        vector<int> nums1,nums2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++){
            if(i != n - 1) nums1.push_back(nums[i]);
            if(i != 0) nums2.push_back(nums[i]);
        }
        int ans1 = find(nums1);
        int ans2 = find(nums2);
        return max(ans1 , ans2);
    }
};
