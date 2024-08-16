class Solution {
private:
    int solve(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        vector<int> dp(end - start + 1, -1);
        int length = end - start + 1;
        if (length == 1) return nums[start];
        if (length == 2) return max(nums[start], nums[start + 1]);
        dp[0] = nums[start];
        dp[1] = max(nums[start + 1], dp[0]);
        for (int i = start + 2; i <= end; i++) {
            dp[i - start] = max(dp[i - start - 1], dp[i - start - 2] + nums[i]);
        }

        return dp[end - start];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int fir = solve(nums, 0, n - 2);
        int las = solve(nums, 1, n - 1);
        return max(fir, las);
    }
};