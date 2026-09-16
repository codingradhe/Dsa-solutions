// 2558. Take Gifts From the Richest Pile
// Easy
// You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

// Choose the pile with the maximum number of gifts.
// If there is more than one pile with the maximum number of gifts, choose any.
// Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.
// Return the number of gifts remaining after k seconds.
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q(gifts.begin(),gifts.end());
        while(k){
            int x = q.top();
            q.pop();
            q.push(sqrt(x));
            k--;
        }
        long long ans = 0;
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};

