// 215. Kth Largest Element in an Array
// Medium
// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?
class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int>q;
        int  n = v.size();
        for(int i = 0;i < n ;i++){
            q.push(v[i]);
        }
        int cnt = 0;
        while(!q.empty()){
            k--;
            int x = q.top();
            if(k == 0) return x;
            q.pop();
        }
        return 0;
    }
};
// ♥️♥️♥️♥️ best meth.od to understand min heap
class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        int  n = v.size();
        for(int i = 0;i < n ;i++){
            q.push(v[i]);
            if(q.size()>k) q.pop();
        }
        return q.top();
    }
};
