class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<long long>>dp(m,vector<long long>(m+1,0));
        for(int len=2;len<m;len++){
            for(int i=0;i<m-len;i++){
                int j= i+len;
                long long minC=INT_MAX;
                for(int k=i+1;k<j;k++){
                    minC = min(minC, cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
                dp[i][j]=minC;
            }
        }
        return dp[0][m-1];
    }
};