// leetcode link -->>https://leetcode.com/problems/backspace-string-compare/?envType=problem-list-v2&envId=stack
// ♥️♥️♥️ beauty thing is this question i have learned if i erase char from string then string lenght will chagne by 1 in whole program 
class Solution {
public:
    string builtStr(string str){
        int j =-1;
        for(int i =0;i<str.size();i++){
            if(str[i] == '#'){
                if(j < 0) {
                    str.erase(i,1);
                    i--;
                }
                else {
                    str.erase(j,2);
                    j--,i = i - 2;
                }
            }
            else j = i;
        }
        return str;
    }
    bool backspaceCompare(string s, string t) {
        s = builtStr(s),t = builtStr(t);
        if(s == t){
            return true;
        }
        return false;
    }
};
