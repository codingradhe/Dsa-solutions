// Alien Dictionary
// Solved
// Difficulty: HardAccuracy:
// An alien language uses the lowercase English alphabet, but the order of its letters is unknown. 
//   You are given an array of strings words[] that is claimed to be sorted lexicographically
// according to the rules of the alien language.

// Determine the order of the letters in the alien alphabet.

// If a valid ordering exists, return a string containing all unique letters in lexicographical 
// order according to the alien language.
// Otherwise, return an empty string.
// If a string s1 is lexicographically smaller than a string s2, and the first position at which
// they differ contains letter a in s1 and letter b in s2, then a must appear before b in the alien alphabet.
// If one word is a prefix of the other, the shorter word must appear before the longer word.

// Note: The driver code prints true if the returned order is valid; otherwise, it prints false.


class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>>& adj,
                         vector<int>& present) {
        vector<int> ans;
        vector<int> degree(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                degree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (present[i] && degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node]) {
                degree[it]--;

                if (degree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return ans;
    }

    string findOrder(vector<string>& words) {
        int n = 26;
        vector<vector<int>> adj(n);
        vector<int> present(n, 0);

        // Mark characters present in the dictionary.
        for (auto& word : words) {
            for (char ch : word) {
                present[ch - 'a'] = 1;
            }
        }

        // Build the graph.
        for (int i = 0; i < (int)words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int size = min(s1.size(), s2.size());
            bool found = false;

            for (int j = 0; j < size; j++) {
                if (s1[j] != s2[j]) {
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    adj[u].push_back(v);
                    found = true;
                    break;
                }
            }

            // Invalid prefix ordering.
            if (!found && s1.size() > s2.size()) {
                return "";
            }
        }

        // Remove duplicate edges.
        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end());
            adj[i].erase(
                unique(adj[i].begin(), adj[i].end()),
                adj[i].end()
            );
        }

        vector<int> result = topoSort(n, adj, present);

        int count = 0;
        for (int i = 0; i < n; i++) {
            count += present[i];
        }

        // A cycle means no valid ordering exists.
        if ((int)result.size() != count) {
            return "";
        }

        string ans;
        for (int ch : result) {
            ans += char(ch + 'a');
        }

        return ans;
    }
};
