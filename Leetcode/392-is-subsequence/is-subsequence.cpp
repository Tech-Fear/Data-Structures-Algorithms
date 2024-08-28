class Solution {
public:
    bool isSubsequence(string s, string t) {
        int subIdx=0;
        for(auto &ch:t){
            if(subIdx==s.length()) break;
            if(s[subIdx]==ch) subIdx++;
        }
        return subIdx==s.length();
    }
};