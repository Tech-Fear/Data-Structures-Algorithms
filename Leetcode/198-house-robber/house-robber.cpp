#define vi vector<int> 
class Solution {
private:
    vi dp;
    int solve(vi &nums,int ind){
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=solve(nums,ind+2)+nums[ind];
        ans=max(ans,solve(nums,ind+1));
        return dp[ind]=ans;
    }
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return solve(nums,0);
    }
};