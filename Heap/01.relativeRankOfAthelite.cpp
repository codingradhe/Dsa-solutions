// 506. Relative Ranks
// Easy
// Topics
// premium lock icon
// Companies
// You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

// The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

// The 1st place athlete's rank is "Gold Medal".
// The 2nd place athlete's rank is "Silver Medal".
// The 3rd place athlete's rank is "Bronze Medal".
// For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
// Return an array answer of size n where answer[i] is the rank of the ith athlete.
// leetcode link -->>    https://leetcode.com/problems/relative-ranks/?envType=problem-list-v2&envId=heap-priority-queue
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& v) {
        int n = v.size();
        vector<string>ans(n);
        priority_queue<pair<int,int>>pq;
        for(int i = 0; i < n;i++){
            pq.push({v[i],i});
        }
        int cnt = 1;
        for(int i = 0;i < n;i++){
            auto it = pq.top();
            pq.pop();
            if(cnt ==1){
                ans[it.second] = "Gold Medal";
                cnt++;
            }
            else if(cnt ==2){
                ans[it.second] = "Silver Medal";
                cnt++;
            }
            else if(cnt ==3){
                ans[it.second] = "Bronze Medal";
                cnt++;
            }
            else{
                ans[it.second] = to_string(cnt);
                cnt++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& v) {
        int n = v.size();
        vector<string>ans(n);
        map<int,string>mp;
        priority_queue<int>pq;
        for(int i = 0; i < n;i++){
            pq.push(v[i]);
        }
        int count = 1;
        for(int i = 0;i < n;i++){
            if(count ==1){
                mp[pq.top()] = "Gold Medal";
                pq.pop();
                count++;
            }
            else if(count ==2){
                mp[pq.top()] = "Silver Medal";
                pq.pop();
                count++;
            }
            else if(count ==3){
                mp[pq.top()] = "Bronze Medal";
                pq.pop();
                count++;
            }
            else{
                mp[pq.top()] = to_string(count);
                pq.pop();
                count++;
            }
        }
        for(int i = 0;i < n;i++){
            ans[i] = mp[v[i]];
        }
        return ans;
    }
};


