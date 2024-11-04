class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return n;
        int maxLength=2;
        vector<unordered_map<int,int>>dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int d=nums[i]-nums[j];
                int len=dp[j][d]+1;
                dp[i][d]=max(dp[i][d],len);
                maxLength=max(dp[i][d]+1,maxLength);
            }
        }
        return maxLength;
    }
};