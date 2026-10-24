// 127. Word Ladder
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// A transformation sequence from word beginWord to word endWord using a dictionary wordList
// is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number
// of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& list) {
        int n = list.size();
        set<string>st;
        for(int i = 0; i < n; i++){
            st.insert(list[i]);
        }
        queue<pair<string,int>>q;
        q.push({bw,1});
        while(!q.empty()){
            int size  = q.size();
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                string s = node.first;
                int dist = node.second;
                int m = s.size();
                for(int j = 0; j < m; j++){
                    for(int k = 0;k < 26; k++){
                        string s1 = s;
                        s1[j] = char(k + 'a');
                        if(s1 == ew && st.find(s1) != st.end()) return dist +1 ;
                        if(st.find(s1) != st.end()){
                            q.push({s1,dist + 1});
                            st.erase(s1);
                        }
                    }
                }
            }

        }
        return 0;
    }
};
