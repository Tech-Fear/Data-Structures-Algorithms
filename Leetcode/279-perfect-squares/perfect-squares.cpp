class Solution {
public:
    int numSquares(int n) {
        vector<int>sq;
        for(int i=0;i*i<=n;i++){
            sq.push_back(i*i);
        }
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            for(auto &s1:sq){
                if(i<s1) break;
                if(dp[i-s1]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-s1]+1);
                }
            }
        }
        return dp[n];
    }
};