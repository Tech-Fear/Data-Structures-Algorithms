class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (j == i + 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
            }
        }

        vector<pair<int, int>> palindromes;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + k - 1; j < n; ++j) {
                if (dp[i][j]) {
                    palindromes.push_back({i, j});
                }
            }
        }
        
        sort(palindromes.begin(), palindromes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        
        int count = 0;
        int lastEnd = -1;
        
        for (const auto& palindrome : palindromes) {
            int start = palindrome.first;
            int end = palindrome.second;
            
            if (start > lastEnd) {
                count++;
                lastEnd = end;
            }
        }

        return count;
    }
};