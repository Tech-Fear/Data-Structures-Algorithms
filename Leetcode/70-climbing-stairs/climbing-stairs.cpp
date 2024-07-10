class Solution {
private:
    int stairs(int i,int n,vector<int>&memo){
        if(i==n) return 1;
        if(memo[i]!=-1) return memo[i];
        int ans=stairs(i+1,n,memo);
        if(i+2<=n) ans+=stairs(i+2,n,memo);
        memo[i]=ans;
        return memo[i];
    }
public:
    int climbStairs(int n) {
        vector<int>memo(n+2,-1);
        return stairs(0,n,memo);
    }
};