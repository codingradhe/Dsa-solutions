// 1482. Minimum Number of Days to Make m Bouquets
// Medium
// You are given an integer array bloomDay,
// an integer m and an integer k.

// You want to make m bouquets. To make a
// bouquet, you need to use k adjacent flowers
// from the garden.

// The garden consists of n flowers, the ith
// flower will bloom in the bloomDay[i] and then
// can be used in exactly one bouquet.

// Return the minimum number of days you
// need to wait to be able to make m 
// bouquets from the garden. If it is
// impossible to make m bouquets return -1.
class Solution {
public:
    int findbd(vector<int>& bd,int k,int mid){
        int ans = 0,n = bd.size(),count = 0;
        for(int i = 0; i < n; i++){
            if(bd[i] <= mid){
                count++;
                if(count == k){
                    ans++;
                    count = 0;
                }
            }
            else count = 0;
        }
        return ans;
    }
    int minDays(vector<int>& bd, int m, int k) {
        int low  = INT_MAX,high = INT_MIN,ans = -1;
        int n = bd.size(),mid;
        for(int i = 0;i < n;i++){
            low = min(low,bd[i]);
            high = max(high,bd[i]);
        }
        while(low <= high){
            mid = low + (high - low)/2;
            int count = findbd(bd,k,mid);
            if(count >= m){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
