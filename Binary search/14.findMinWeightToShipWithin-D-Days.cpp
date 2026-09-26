// 1011. Capacity To Ship Packages Within D Days
// Medium
// A conveyor belt has packages that must be shipped
// from one port to another within days days.

// The ith package on the conveyor belt has a
// weight of weights[i]. Each day, we load the
// ship with packages on the conveyor belt 
// (in the order given by weights). We may 
// not load more weight than the maximum weight
// capacity of the ship.

// Return the least weight capacity of the ship
// that will result in all the packages on the 
// conveyor belt being shipped within days days.
class Solution {
public:
    int countdays(vector<int>& w, int mid){
        int days = 1;
        int sum = 0;
    
        for(int i = 0; i < w.size(); i++){
            if(sum + w[i] > mid){
                days++;
                sum = 0;
            }
    
            sum += w[i];
        }
    
        return days;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size(),mid,high = 0, ans;
        int low = *max_element(w.begin(), w.end());
        for(auto it : w){
            high += it;
        }
        while(low <= high){
            mid = low + (high - low)/2;
            int d = countdays(w,mid);
            if(d <= days) {
               ans = mid;
                high =  mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

