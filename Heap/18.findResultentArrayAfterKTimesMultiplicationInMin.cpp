// 3264. Final Array State After K Multiplication Operations I
// Easy
// You are given an integer array nums, an integer k, and
// an integer multiplier.

// You need to perform k operations on nums. In each operation:

// Find the minimum value x in nums. If there are multiple
// occurrences of the minimum value, select the one that
// appears first.
// Replace the selected minimum value x with x * multiplier.
// Return an integer array denoting the final state of nums 
// after performing all k operations.
typedef pair<int,int> p;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
priority_queue<p,vector<p>,greater<p>>q;
        for(int i = 0;i < nums.size();i++){
            q.push({nums[i],i});
        }
        while(k){
            auto it = q.top();
            q.pop();
            q.push({it.first*multiplier,it.second});
            k--;
        }
        for(int i = 0;i < nums.size();i++){
            auto it = q.top();
            q.pop();
            nums[it.second] = it.first;
        }
        return nums;
    }
};
