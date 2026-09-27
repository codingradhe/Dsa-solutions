// 4. Median of Two Sorted Arrays
// Hard
// Given two sorted arrays nums1 and nums2 of size m
// and n respectively, return the median of the 
// two sorted arrays.

// The overall run time complexity should be 
// O(log (m+n)).

// brute force solution

class Solution {
public:
    vector<int>merge(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size(),m = nums2.size();
        int i = 0,j = 0,k = 0;
        vector<int>ans(m + n);
        while(i < n && j < m){
            if(nums1[i] <= nums2[j]){
                ans[k] = nums1[i];
                k++,i++;
            }
            else{
                ans[k] = nums2[j];
                k++,j++;
            }
        }
        while(i < n){
            ans[k] = nums1[i];
            k++,i++;
        }
        while(j < m){
            ans[k] = nums2[j];
            k++,j++;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size(),m = nums2.size();
        vector<int>ans = merge(nums1,nums2);
        if((m+n) % 2 == 0){
            double x = ans[(m+n)/2];
            double y = ans[(m+n)/2 - 1];
            return (x+y)/2;
        }
        else{
            double x = ans[(m+n)/2];
            return x;
        }
    }
};
// optimal solution
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size(),n2 = nums2.size();
        int n = n1 + n2;
        if(n1 > n2) return findMedianSortedArrays(nums2,nums1);
        int left = (n1 + n2 + 1)/2;
        int low = 0,high = n1;
        while(low <= high){
            int mid1 = low + (high - low)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN,l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 > 0) l1 = nums1[mid1 -1];
            if(mid2 > 0) l2 = nums2[mid2 -1];
            if(l1 <= r2 && l2 <= r1){
                if(n % 2 != 0) return max(l1,l2);
                else return (double(max(l1,l2) + min(r1,r2)))/2.0;
            }
            if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0;
    }
};

