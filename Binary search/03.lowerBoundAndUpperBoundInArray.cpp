// Implement Lower Bound
// Solved
// Given a sorted array arr[] (following 0-based indexing) and a number target, find the lower bound of the target in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.

// Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 
// class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int low = 0,high = arr.size()-1,mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(arr[mid] == target) {
                while(mid >0 && arr[mid] == arr[mid-1]) mid--;
                return mid;
            }
            else if(arr[mid] > target) high = mid -1;
            else low = mid + 1;
        }
        return low;
    }
};

// Implement Upper Bound
// Solved
// Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.
// The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

// Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.Implement Upper Bound
// Solved
// Difficulty: EasyAccuracy: 52.54%Submissions: 73K+Points: 2
// Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.
// The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

// Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.
  class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int low = 0,high = arr.size()-1,mid;
        if(arr[arr.size()-1] <= target ) return arr.size();
        while(low <= high){
            mid = low + (high - low)/2;
            if(arr[mid] == target) {
                while(mid < arr.size() -2 && arr[mid] == arr[mid+1]) mid++ ;
                return mid + 1;
            }
            else if(arr[mid] > target) high = mid -1;
            else low = mid + 1;
        }
        return low;
    }
};


