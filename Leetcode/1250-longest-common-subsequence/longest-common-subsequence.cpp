typedef vector<int> v32;
typedef vector<vector<int>> vv32;
class Solution {
private:
    int solve(string &s1, string &s2, int m, int n, vv32 &dp) {
        if (n == 0 || m == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        if (s1[m-1] == s2[n-1]) {
            dp[m][n] = solve(s1, s2, m-1, n-1, dp) + 1;
        } else {
            dp[m][n] = max(solve(s1, s2, m-1, n, dp), solve(s1, s2, m, n-1, dp));
        }
        return dp[m][n];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vv32 dp(text1.length()+1,v32(text2.length()+1,-1));
        return solve(text1,text2,text1.length(),text2.length(),dp);
    }
};