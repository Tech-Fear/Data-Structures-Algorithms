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
    int change(int amount, v32 &arr) {
        // vv32 dp(arr.size()+1,v32(amount+1,-1));
        // return solve(0,amount,arr,dp);
        fast_cin();
        int n=arr.size();
        vv32 dp(n+1,v32(amount+1,0));
        dp[n][amount]=1;
        for(int i=0;i<amount;i++){
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=amount;j>=0;j--){
                dp[i][j]=dp[i+1][j];
                if(j+arr[i]<=amount){
                    dp[i][j]+=dp[i][j+arr[i]];
                }
            }
        }
        return dp[0][0];
    }
};
