// Count Islands After Every Operation
// Given a grid of n rows and m columns. Initially, all cells of the grid contain 0, where 0 represents water.

// You are also given a 2D array operators[][], where each operator contains two integers 
// representing the row and column of a cell.
// Each operation converts the specified water cell into land by changing its value from 0 to 1.
// Return an array containing the number of islands after each operation.

// An island is a group of one or more land cells (or 1s) with the following properties,

// 1s are connected through their top, bottom, left, or right sides.
// Diagonally connected are not considered part of the same island.

class Solution {
	void dfs(int node, vector<vector<int>> &adj, vector<int>&vis) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) {
				dfs(it, adj, vis);
			}
		}
		return;
	}
	public:
	int count(vector<vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		int cnt = 0;
		vector<vector<int>> adj(m * n);
		vector<int> vis(m * n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i > 0) {
					if (grid[i - 1][j] == 1)
						adj[cnt].push_back(cnt - m);
				}
				if (i < n - 1) {
					if (grid[i + 1][j] == 1)
						adj[cnt].push_back(cnt + m);
				}
				if (j > 0) {
					if (grid[i][j - 1] == 1)
						adj[cnt].push_back(cnt - 1);
				}
				if (j < m - 1) {
					if (grid[i][j + 1] == 1)
						adj[cnt].push_back(cnt + 1);
				}
				cnt++;
			}
		}
		int ans = 0;
		int size = m*n;
		for (int i = 0; i < size; i++) {
			if (grid[i/m][i%m] == 1 && !vis[i]) {
				dfs(i, adj, vis);
				ans++;
			}
		}
		return ans;
	}
	vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
		vector<vector<int>> grid(n, vector<int>(m, 0));
		int size = op.size();
		vector<int>ans;
		for (auto it : op) {
			int row = it[0];
			int col = it[1];
			grid[row][col] = 1;
			ans.push_back(count(grid));
		}
		return ans;
	}
};
