typedef vector<vector<long long>> vv64;
typedef vector<long long> v64;
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        fast_cin();
        int n = grid.size();
        int m = grid[0].size();
        vv64 dp(n, v64(m, LLONG_MAX));
        for (int j = 0; j < m; j++) {
            dp[n - 1][j] = grid[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                ll ans = dp[i + 1][j]; 
                if (j > 0) ans = min(ans, dp[i + 1][j - 1]);
                if (j < m - 1) ans = min(ans, dp[i + 1][j + 1]);
                dp[i][j] = grid[i][j] + ans;
            }
        }
        ll minSum = LLONG_MAX;
        for (int j = 0; j < m; j++) {
            minSum = min(minSum, dp[0][j]);
        }
        return minSum;
    } 
};