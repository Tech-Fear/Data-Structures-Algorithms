class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        int l,r;
        for(int i=0;i<s.length();i++){
            l=i;r=i;//odd length
            while(l>=0 && r<s.length() && s[l]==s[r]){
                r++;l--;res++;
            }
            l=i;r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                r++;l--;res+=1;
            }
        }
        return res;
    }
};