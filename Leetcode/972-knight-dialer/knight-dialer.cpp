class Solution {
    const int mod=1e9+7;
    int solve(int c,int n,unordered_map<int,vector<int>>&mp,vector<vector<int>>&dp){
        if(n==0) return 1;
        if(dp[c][n]!=-1) return dp[c][n];
        int temp=0;
        for(auto &v:mp[c]){
            temp = (((temp)%mod) + (solve(v,n-1,mp,dp)%mod))%mod;
        }
        return dp[c][n]=temp;
    }
public:
    int knightDialer(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<vector<int>>dp(10,vector<int>(n,-1));
        unordered_map<int,vector<int>>mp;
        mp[0]={4,6};
        mp[1]={6,8};
        mp[2]={7,9};
        mp[3]={4,8};
        mp[4]={0,3,9};
        mp[5]={};
        mp[6]={0,1,7};
        mp[7]={2,6};
        mp[8]={1,3};
        mp[9]={4,2};
        int count=0;
        for(int i=0;i<=9;i++){
            count = (((count)%mod) + (solve(i,n-1,mp,dp)%mod))%mod;
        }
        return count;
    }
};