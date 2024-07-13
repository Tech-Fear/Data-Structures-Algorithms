class Solution {
private:
    int solve(int i, int sum, int x, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == n) {
            return (x - (2 * sum)) == 0 ? 1 : 0;
        }
        if (dp[i][sum] != -1) return dp[i][sum];
        int include = (nums[i] <= x) ? solve(i + 1, sum + nums[i], x, n, nums, dp) : 0;
        int exclude = solve(i+1,sum,x,n,nums,dp);
        return dp[i][sum] = include || exclude;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (auto i : nums){
            x+=i;
        }
        vector<vector<int>> dp(n, vector<int>(x, -1));
        return solve(0, 0, x, n, nums, dp);
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return ';';
}();