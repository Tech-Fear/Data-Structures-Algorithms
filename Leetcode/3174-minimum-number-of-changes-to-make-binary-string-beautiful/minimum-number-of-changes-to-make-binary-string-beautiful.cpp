class Solution {
public:
    int minChanges(string s) {
        int count=0;
        for(int i=1;i<s.length();i+=2){
            count+=(s[i]!=s[i-1]);
        }
        return count;
    }
};