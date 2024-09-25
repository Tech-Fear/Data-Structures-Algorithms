class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp(3,0);
        int sum=0;
        for(auto &num:nums){
            vector<int>temp1=dp;
            for(int i=0;i<3;i++){
                int temp=temp1[i]+num;
                dp[temp%3]=max(dp[temp%3],temp);
            }
        }
        return dp[0];
    }
};