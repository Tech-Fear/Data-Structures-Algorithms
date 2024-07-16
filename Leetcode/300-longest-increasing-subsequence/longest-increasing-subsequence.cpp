typedef vector<int> v32;
typedef vector<vector<int>> vv32;
class Solution {
private:
    int solve(int i, v32& arr, int n, int idx, vv32& dp) {
        if (i == n)
            return 0;

        if (dp[i][idx + 1] != -1)
            return dp[i][idx + 1];

        int include = 0;
        if (idx == -1 || arr[idx] < arr[i]) {
            include = solve(i + 1, arr, n, i, dp) + 1;
        }

        int exclude = solve(i + 1, arr, n, idx, dp);
        return dp[i][idx + 1] = max(include, exclude); 
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vv32 dp(n, v32(n + 1, -1));
        return solve(0, nums, n, -1, dp);
    }
};