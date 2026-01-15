class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<int> a(size), b(size);
        array<array<int, 101>, 101> dp{};
        for (int i = 0; i < size; i++) {
            int c1 = 0, c0 = 0;
            for (int j = 0; j < strs[i].length(); j++) {
                if (strs[i][j] == '1') {
                    c1 += 1;
                } else {
                    c0 += 1;
                }
            }
            for (int i = m; i >= c0; --i)
                for (int j = n; j >= c1; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - c0][j - c1]);
                }
        }
        return dp[m][n];
    }
};