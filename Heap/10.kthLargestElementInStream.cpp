// 703. Kth Largest Element in a Stream
// Easy
// You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

// You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

// Implement the KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
// int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 
class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>>q;
    KthLargest(int k, vector<int>& v) {
        this->k = k;
        int n = v.size();
        for(int i = 0;i < n;i++){
            q.push(v[i]);
            if(q.size() > k) q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>k) q.pop();
        return q.top();
    }
};

