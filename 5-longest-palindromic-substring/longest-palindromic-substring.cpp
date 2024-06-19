class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        int i,j,len=1,point=0;
        for(int k=0;k<n;k++){
            i=k,j=k+1;
            while(i>=0 && j<s.length()&& s[i]==s[j]){
                if(j-i+1>len){
                    point=i;
                    len=j-i+1;
                }
                i--;j++;
            }
            i=k;
            j=k;
            while(i>=0 && j<s.length()&& s[i]==s[j]){
                if(j-i+1>len){
                    point=i;
                    len=j-i+1;
                }
                i--;j++;
            }
            
        }
        string t="";
        for(int i=point ;i<point+len;i++)t+=s[i];
        return t;
    }
};