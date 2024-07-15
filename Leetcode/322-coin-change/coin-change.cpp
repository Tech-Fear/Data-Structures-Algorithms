#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
class Solution {
private:
    int solve(int i,int amount,v32 &coins,vv32 &dp){
      if(i==coins.size()){
        if(amount==0) return 0;
        return 1e8;
      }
      if(dp[i][amount]!=-1) return dp[i][amount];
      int ans=1e8;
      ans=solve(i+1,amount,coins,dp);
      if(coins[i]<=amount){
        ans=min(ans,solve(i,amount-coins[i],coins,dp)+1);
      }
      return dp[i][amount]=ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        fast_cin();
        vv32 dp(coins.size()+1,v32(amount+1,-1));
        int ans=solve(0,amount,coins,dp);
        if(ans==1e8) return -1;
        return ans;
    }
};