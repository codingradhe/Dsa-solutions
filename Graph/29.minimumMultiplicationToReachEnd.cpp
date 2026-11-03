// Minimum Multiplications to Reach End
// Solved

// Given two integers, start and end, along with an array of integers arr[]. 
// In one operation, you can multiply the current value by any element from arr[],
// and then take the result modulo 1000 to obtain a new value.

// Find the minimum steps in which end can be achieved starting from start.
// If it is not possible to reach end, then return -1.

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        int n = arr.size();
      // max  number number of node you can reach because of modulo
        vector<int>dist(1000,INT_MAX);
      // you dont need to make priority queue because of you always go by one step so use queue
        queue<pair<int,int>> q;
        q.push({start, 0});
        if(start == end ) return 0;
        dist[start] = 0;
        while(!q.empty()){
            auto ptr = q.front();
            int node = ptr.first;
            int step = ptr.second;
            q.pop();
            for(auto it : arr){
                int multi = (node * it) % 1000;
              // if someone reach first no need to go that path again
                if(step + 1 < dist[multi]){
                    if(multi == end) return step + 1;
                    q.push({multi , step + 1});
                    dist[multi] = step + 1;
                }
            }
        }
        return -1;
    }
};
