// 1338. Reduce Array Size to The Half
// Medium
// You are given an integer array arr. You can
// choose a set of integers and remove all the
// occurrences of these integers in the array.
// Return the minimum size of the set so that at
// least half of the integers of the array are removed.
typedef pair<int,int> p; 
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int>q;
        int n = arr.size();
        map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        for(auto it:mp){
            q.push(it.second);
        }
        int sum = 0,ans = 0;
        while(sum < n/2){
            ans++;
            int t = q.top();
            sum += t;
            q.pop();
        }
        return ans;
    }
};
