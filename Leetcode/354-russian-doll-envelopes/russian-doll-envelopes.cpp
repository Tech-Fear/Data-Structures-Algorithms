class Solution {
    int LIS_ON2(vector<vector<int>>&envelopes){ //Will give TLE as it has complexity of O(N^2) ans constraint is of 10^5
        int ans=0;
        int n=envelopes.size();
        vector<int>dp(n,1);
         for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    int LIS(vector<vector<int>>&envelopes){
        vector<int>dp;
        int n=envelopes.size();
        for(int i=0;i<n;i++){
            auto j=std::lower_bound(dp.begin(),dp.end(),envelopes[i][1]);
            if(j==dp.end()) dp.push_back(envelopes[i][1]);
            else *j=envelopes[i][1];
        }
        return dp.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if(n==0) return 0;
        int ans=0;
        sort(envelopes.begin(),envelopes.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int>dp(n,1);
        return ans=LIS(envelopes);
    }
};