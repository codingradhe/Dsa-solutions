// Minimum Spanning Tree
// Solved
// Given a weighted, undirected, and connected graph represented by an adjacency
// list adj[][][], where adj[u] contains pairs [v, w] representing an edge from u to v with weight w.

// Find the total weight of its Minimum Spanning Tree (MST) using Prim's Algorithm.


class Solution {
	public:
	int primMST(vector<vector<vector<int>>> &adj) {
		int n = adj.size();
		
		priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;

		int ans = 0;
		vector<int> vis(n, 0);
		
		pq.push({0, {0, -1}});
		
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			
			int d = it.first;
			int node = it.second.first;
			int parent = it.second.second;
			
			if (vis[node]) continue;
			vis[node] = 1;
			ans += d;
			
			for (auto ptr : adj[node]) {
				int adnode = ptr[0];
				int wt = ptr[1];
				
				if (!vis[adnode]) {
					pq.push({wt, {adnode, node}});
				}
			}
		}
		
		return ans;
	}
};
