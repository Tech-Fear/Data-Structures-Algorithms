#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
class Solution {
private:
  int solve(int i,int amount,v32 &coins,vv32 &dp){
    if(i>=coins.size()) return 0;
    if(amount==0) return 1;
    if(dp[i][amount]!=-1) return dp[i][amount];
    int np = solve(i+1,amount,coins,dp);
    int p = 0;
    if(amount>=coins[i]){
          p = solve(i,amount-coins[i],coins,dp);
    }
    return dp[i][amount] = p+np;
  }
public:
    int change(int amount, v32 &coins) {
        vv32 dp(coins.size()+1,v32(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};
