// 2335. Minimum Amount of Time to Fill Cups
// Easy
// You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

// You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.
// leetcode link -->>https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/?envType=problem-list-v2&envId=heap-priority-queue
class Solution {
public:
    int fillCups(vector<int>& v) {
        priority_queue<int>q;
        for(int i = 0;i < 3;i++){
            if(v[i] != 0) q.push(v[i]);
        }
        int ans = 0;
        while(!q.empty()){
            int t1 = q.top();
            q.pop();
            if(!q.empty()){
                int t2 = q.top();
                q.pop();
                t2--;
                if(t2 > 0) q.push(t2);
            }
            t1--;
            if(t1 > 0) q.push(t1);
            ans++;
        }
        return ans;
    }
};
