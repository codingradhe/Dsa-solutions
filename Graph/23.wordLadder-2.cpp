// 126. Word Ladder II
// Attempted
// Hard
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a 
// sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest 
// transformation sequences from beginWord to endWord, or an empty list if no such sequence exists.
//   Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

class Solution {
public:
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& list) {
        int n = list.size();
        set<string>st;
        for(int i = 0; i < n; i++){
            st.insert(list[i]);
        }
        vector<string>used;
        used.push_back(bw);
        vector<vector<string>>ans;
        queue<vector<string>>q;
        q.push({bw});
        int level = 0;
        while(!q.empty()){
            vector<string>vec = q.front();
            q.pop();
            if(vec.size() > level) {
                level++;
                for(auto it:used){
                    st.erase(it);
                }
            }
            string s = vec.back();
            if(s == ew){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(vec.size() == ans[0].size()){
                    ans.push_back(vec);
                }
            }
            for(int i = 0; i < s.size(); i++){
                char original = s[i];
                for(char c = 'a'; c <= 'z'; c++){
                    s[i] = c;
                    if(st.find(s) != st.end()){
                        vec.push_back(s);
                        used.push_back(s);
                        q.push(vec);
                        vec.pop_back();
                    }
                }
                s[i] = original;
            }
        }
        return ans;
    }
};
