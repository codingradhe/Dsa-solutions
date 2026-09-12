// 🖊️🖊️🖊️ weight destroy by max to second min and return last weight stone
// 1046. Last Stone Weight
// Easy
// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0.
// leetcode link -->>  https://leetcode.com/problems/last-stone-weight/?envType=problem-list-v2&envId=heap-priority-queue
class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int>q;
        for(auto it: v){
            q.push(it);
        }
        while(q.size() > 1){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if(a > b) q.push(a-b);
        }
        if(q.empty()) return 0;
        return q.top();
    }
};
