class Solution {
public:
    int solve(vector<int>& nums, int target, int sum, int ind, vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            return sum == target ? 1 : 0;
        }
        if (dp[ind][sum + 1000] != -1) return dp[ind][sum + 1000];
        int plus = solve(nums, target, sum + nums[ind], ind + 1, dp);
        int minus = solve(nums, target, sum - nums[ind], ind + 1, dp);
        return dp[ind][sum + 1000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return solve(nums, target, 0, 0, dp);
    }
};
