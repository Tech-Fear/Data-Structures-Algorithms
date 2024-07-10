class Solution {
private:
    int calc(int n,vector<int>&memo){
        if(memo[n]!=-1) return memo[n];
        if(n==0 || n==1) return n;
        return memo[n]=calc(n-1,memo)+calc(n-2,memo);
    }
public:
    int climbStairs(int n) {
        vector<int>memo(n+2,-1);
        memo[0]=1,memo[1]=1;
        return calc(n,memo);
    }
};