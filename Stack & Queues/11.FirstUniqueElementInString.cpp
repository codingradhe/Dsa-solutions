// brute force solution tc = O(n)
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        int n = s.size();
        for(int i = 0;i < n;i++){
            mp[s[i]]++;
        }
        for(int i = 0;i < n;i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};
// optinal solution 
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;       
    }
};
