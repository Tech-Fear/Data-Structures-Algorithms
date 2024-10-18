class Solution {
public:
    void solve(vector<int>&nums,int &target,int sum,int &ans,int ind){
        if(nums.size()==ind){
            if(target==sum) ans++;
            return;
        }
        // + sign
        solve(nums,target,sum+nums[ind],ans,ind+1); 
        // -sign
        solve(nums,target,sum-nums[ind],ans,ind+1); 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        solve(nums,target,0,ans,0);
        return ans;
    }
};