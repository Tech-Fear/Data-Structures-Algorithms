class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            dp[i]+=dp[i+1];
            if(i+2<=n) dp[i]+=dp[i+2];
        }
        return dp[0];
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '$';
}();