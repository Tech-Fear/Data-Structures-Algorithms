class Solution {
    int dirX[4] = {1, 0, -1, 0};
    int dirY[4] = {0, 1, 0, -1};
    
    bool check(int r, int c, int m, int n) {
        return r >= 0 && c >= 0 && r < m && c < n;
    }
    
    int MOD = 1e9 + 7;
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        dp[0][startRow][startColumn] = 1;
        
        int totalPaths = 0;
        
        for (int k = 1; k <= maxMove; ++k) {
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dp[k - 1][r][c] > 0) {
                        for (int d = 0; d < 4; ++d) {
                            int newRow = r + dirX[d];
                            int newCol = c + dirY[d];
                            if (!check(newRow, newCol, m, n)) {
                                totalPaths = (totalPaths + dp[k - 1][r][c]) % MOD;
                            } else {
                                dp[k][newRow][newCol] = (dp[k][newRow][newCol] + dp[k - 1][r][c]) % MOD;
                            }
                        }
                    }
                }
            }
        }
        
        return totalPaths;
    }
};
