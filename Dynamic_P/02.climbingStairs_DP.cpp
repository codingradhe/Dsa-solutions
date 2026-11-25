// 70. Climbing Stairs
// Solved
// Easy
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

class Solution {
public:
    int climbStairs(int n) {
//😍❤️❤️ dp method other method give tle by calculating all possible ways as bottom code is written
        if(n <= 2) return n;

        int prev2 = 1;
        int prev1 = 2;

        for(int i = 3; i <= n; i++) {

            int curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

// using queue data structure
class Solution {
public:
    int climbStairs(int n) {
        queue<int>q;
        q.push(0);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int x = q.front();
                q.pop();
                if(x == n) ans++;
                if(x >= n) continue;
                q.push(x + 1);
                q.push(x + 2);
            }       
        }
        return ans;
    }
};
