// 1464. Maximum Product of Two Elements in an Array
// Easy
// You are given an array of integers nums.

// Choose two different indices i and j of that array.

// Return the maximum value of (nums[i] - 1) * (nums[j] - 1).
// leetcode link -->> https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=problem-list-v2&envId=heap-priority-queue
class Solution {
public:
    int maxProduct(vector<int>& v) {
        int first = INT_MIN;
        int second  = INT_MIN;
        for(int i = 0;i < v.size();i++){
            if(v[i] >= first) {
                second = first;
                first = v[i];
            }
            else if(v[i] < first && v[i] > second) second = v[i];
        }
        return (first-1)*(second-1);
    }
};
