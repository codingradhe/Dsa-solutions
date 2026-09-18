// 3507. Minimum Pair Removal to Sort Array I
// Easy
// Given an array nums, you can perform the following
// operation any number of times:

// Select the adjacent pair with the minimum sum
// in nums. If multiple such pairs exist, choose
// the leftmost one.
// Replace the pair with their sum.
// Return the minimum number of operations needed
// to make the array non-decreasing.

// An array is said to be non-decreasing if each element is
// greater than or equal to its previous element 
// (if itexists).


class Solution {  
public:  
    int minimumPairRemoval(vector<int>& nums) {  
        int cnt = 0;  
        while(nums.size() > 1){  
            bool ascending = true;  
            int minidx = 0,minsum = nums[0] + nums[1];  
            for(int i = 0; i < nums.size()-1;i++){  
                int sum = nums[i] + nums[i+1];
                if(nums[i] > nums[i+1]) ascending = false;
                if(sum < minsum){  
                    minsum = sum;    
                    minidx = i;  
                }  
            }  
            if(ascending) break;  
            cnt++;  
            nums[minidx] = minsum;  
            nums.erase(nums.begin()+minidx+1);  
        }  
        return cnt;  
    }  
};  
