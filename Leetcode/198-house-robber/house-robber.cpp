class Solution {
private:
    int solve(vector<int>&dp,int ind,vector<int>&nums){
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=solve(dp,ind+2,nums)+nums[ind];
        ans=max(ans,solve(dp,ind+1,nums));
        return dp[ind]=ans;

    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int>dp(nums.size(),-1);
        return solve(dp,0,nums);

    }
};