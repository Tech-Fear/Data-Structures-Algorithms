class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1=word1.length(),s2=word2.length();
        vector<vector<int>>dp(s1+1,vector<int>(s2+1,0));
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return (s1-dp[s1][s2])+(s2-dp[s1][s2]);
    }
};