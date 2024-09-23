class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            // for 1 day
            int cost1 = costs[0] + dp[i + 1];
            // for 7days
            int skipdays=i;
            
            while(skipdays<n and days[skipdays]<days[i]+7){
                skipdays++;
            }
            int cost7=costs[1]+dp[skipdays];
            //for 30 days
            int skipdays30=i;
            
            while(skipdays30<n and days[skipdays30]<days[i]+30){
                skipdays30++;
            }
            int cost30=costs[2]+dp[skipdays30];
            dp[i]=min(cost1,min(cost7,cost30));
        }
        return dp[0];
    }
};