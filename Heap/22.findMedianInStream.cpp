// Find Median in a Stream
// Given a data stream arr[] where integers
// are read sequentially, find the median
// of the elements encountered so far after
// each new integer is read.

// The median is defined as follows:

// Odd number of elements: The median is
// the middle element when the current set 
// of numbers is sorted.
// Even number of elements: The median is
// the arithmetic mean (average) of the two
// middle elements when the current set of
// numbers is sorted.
// gfg link of this problem-->>   https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
  class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;

        // q1 = smaller half (max heap)
        priority_queue<int> q1;

        // q2 = larger half (min heap)
        priority_queue<int, vector<int>, greater<int>> q2;

        for(int x : arr) {

            // Step 1: Insert into correct heap
            if(q1.empty() || x <= q1.top())
                q1.push(x);
            else
                q2.push(x);

            // Step 2: Balance sizes
            if(q1.size() > q2.size() + 1) {
                q2.push(q1.top());
                q1.pop();
            }
            else if(q2.size() > q1.size()) {
                q1.push(q2.top());
                q2.pop();
            }

            // Step 3: Find median
            if(q1.size() == q2.size()) {
                double median =
                    ((double)q1.top() + (double)q2.top()) / 2.0;

                ans.push_back(median);
            }
            else {
                ans.push_back((double)q1.top());
            }
        }

        return ans;
    }
};
