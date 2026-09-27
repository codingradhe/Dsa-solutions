// Aggressive Cows
// Solved
// Given an integer array arr[], which denotes the positions
// of stalls. All the positions are distinct. There are k 
// aggressive cows.

// Assign the cows to the stalls such that the minimum
// distance between any two cows is maximized.
// leetcode link -->> https://www.geeksforgeeks.org/problems/aggressive-cows/1
// ♥️♥️♥️ approach -\
// first sort array to placed cow in orde
// second -- set minimum to 1 and maximum to distance between first and last stall ;
// perform binary search to maximize minimum distance between cow 
class Solution {
  public:
    int cowplaced(vector<int> &arr, int mid){
        int ans = 1;
        int j = 0;
        for(int i = 1;i < arr.size(); i++){
            if(arr[i] - arr[j] >= mid){
                j = i;
                ans++;
            }
        }
        return ans;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int low = 1,mid , high = arr[n-1] - arr[0],ans;
        while(low <= high){
            mid = low + (high - low)/2;
            int cp = cowplaced(arr,mid);
            if(cp >= k){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
