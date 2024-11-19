class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum=0,curSum=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            curSum+=nums[i];
            mp[nums[i]]++;
            if(i>=k-1){
                if(mp.size()==k) maxSum=max(maxSum,curSum);
                curSum-=nums[i-k+1];
                mp[nums[i-k+1]]--;
                if(mp[nums[i-k+1]]==0) mp.erase(nums[i-k+1]);
            }
        }
        return maxSum;
    }
};