// 746. Min Cost Climbing Stairs
// Solved
// Easy
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase.

// Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the staircase, which is the 
// position just past the last step (index cost.length).

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      // Using dp array😍👌👌🤣🤣
        // int n = cost.size();
        // if(n <= 2) return min(cost[0],cost[1]);
        // vector<int>price(n,0);
        // price[0] = cost[0], price[1] = cost[1];
        // for(int i = 2;i < n; i++){
        //     price[i] = min(price[i-1],price[i -2]) + cost[i];
        // }
        // return min(price[n -1], price[n -2]);
// optimal using memorization ❤️❤️❤️💕💕💕💕
        int n = cost.size();
        if(n == 1) return cost[0];
        if(n <= 2) return min(cost[0],cost[1]);
        int pre = cost[1] , spre =  cost[0];
        for(int i = 2;i < n; i++){
            int curr = min(pre,spre) + cost[i];
            spre = pre;
            pre = curr;
        }
        return min(pre,spre);
    }
};
