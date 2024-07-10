class Solution {
private:
    int fibo(int n,vector<int>&memo){
        if(memo[n]!=-1) return memo[n];
        if(n==0 || n==1) return n;
        memo[n]=fibo(n-1,memo)+fibo(n-2,memo);
        return memo[n];
    }
public:
    int fib(int n) {
        vector<int>memo(n+2,-1);
        memo[1]=1;
        memo[0]=0;
        return fibo(n,memo);
    }
};