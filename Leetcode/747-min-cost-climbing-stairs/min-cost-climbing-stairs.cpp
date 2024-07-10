class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1);
        dp[n]=0;
        dp[n-1]=cost[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};
/* int min_cost(int n,cost){
    if(n==0 || n==1) return 0;
    int ans=min_cost(n-1,cost)+cost[n-1];
    if(n-2>=0){
        ans+=min(ans,min_cost(n-2)++cost[n-2]);
    }
    return ans;
}
*/