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
        // return solve(nums,0);
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};
