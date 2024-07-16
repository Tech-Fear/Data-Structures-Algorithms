typedef vector<int> v32;
typedef vector<vector<int>> vv32;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
class Solution {
public:
    int minDistance(string word1, string word2) {
        fast_cin();
        int n=word1.length();
        int m=word2.length();
        vv32 dp(n+1,v32(m+1,0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
            else {
              dp[i][j]=min(dp[i-1][j]+1,min(dp[i-1][j-1]+1,dp[i][j-1]+1));
            }
          }
        }
        return dp[n][m];
    }
};