class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=1;
        int lastIndex=0;
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int>ans;
        while(hash[lastIndex]!=lastIndex){
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        return ans;
    }
};