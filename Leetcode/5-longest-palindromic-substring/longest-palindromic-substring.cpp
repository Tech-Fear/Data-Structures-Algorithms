class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int start=0;
        int maxLength=1;
        //length 1
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        //length 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                start=i;
                maxLength=2;
            }
        }

        for(int l=3;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = l;
                }
            }
        }
        return s.substr(start,maxLength);
    }
};