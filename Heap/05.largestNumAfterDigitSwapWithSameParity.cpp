// 2231. Largest Number After Digit Swaps by Parity
// Easy
// You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

// Return the largest possible value of num after any number of swaps.
// leetcode link  https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/?envType=problem-list-v2&envId=heap-priority-queue
class Solution {
public:
    int reverse(int num){
        int ans = 0;
        while(num){
            ans = ans*10 + num%10;
            num /=10;
        }
        return ans;
    }
    int largestInteger(int num) {
        priority_queue<int>qodd,qeven;
        int rev = reverse(num);
        int ans = 0;
        while(num){
            if(num%2 == 0) {
                qeven.push(num%10);
            }
            else {
                qodd.push(num%10);
            }
            num/=10;
        }
        while(!qodd.empty()||!qeven.empty()){
            if(rev%2 != 0){
                if(!qodd.empty()){
                    int t = qodd.top();
                    ans = ans*10 + t;
                    qodd.pop();
                }
            }
            else{
                if(!qeven.empty()){
                    int t = qeven.top();
                    ans = ans*10 + t;
                    qeven.pop();
                }
            }
            rev/=10;
        }
        return ans;
    }
};
