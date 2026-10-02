// 165. Minimize Max Distance to Gas Station


// Given a sorted array arr of size n, containing integer
// positions of n gas stations on the X-axis, and an integer
// k, place k new gas stations on the X-axis.

// The new gas stations can be placed anywhere on the
// non-negative side of the X-axis, including non-integer
//   positions.

// Let dist be the maximum distance between adjacent
// gas stations after adding the k new gas stations.

// Find the minimum value of dist.

// Your answer will be accepted if it is within 1e-6
//   of the true value.
class Solution {
public:
    int cntused(vector<int> &arr, long double mid){
        int cnt = 0;
        for(int i = 0;i < arr.size(); i++){
            cnt += ceil(arr[i] / mid) - 1;
        }
        return cnt;
    }
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        long double low = 0 ,high = 0,mid;
        for(int i = 0;i < n - 1; i++){
            arr[i] = arr[i + 1] - arr[i];
            high = max(high , (long double)arr[i]);
        }
        long double ans;
        arr.pop_back();
        while (high - low > 1e-6) {
            long double mid = low + (high - low) / 2;
            int cnt = cntused(arr,mid);
            if (cnt <= k){
                ans = mid;
                high = mid;
                // answer is  right
            }
            else low = mid;      
            // answer is to the left
        }
        return ans;
    }
};
