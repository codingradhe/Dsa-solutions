// 744. Find Smallest Letter Greater Than Target
// Easy
// You are given an array of characters letters
// that is sorted in non-decreasing order, and a
// character target. There are at least two different
// characters in letters.

// Return the smallest character in letters that is
// lexicographically greater than target. If such a
// character does not exist, return the first character
// in letters.
class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char target) {
        int low = 0, high = v.size()-1,mid;
        char ans = v[v.size() -1];
        bool get = false;
        while(low <= high){
            mid = low + (high - low)/2;
            if(v[mid] > target){
                ans = min(ans , v[mid]);
                get = true;
                high = mid -1;
            }
            else low = mid + 1;
        }
        if(get ) return ans;
        return v[0];
    }
};
