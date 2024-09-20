class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int size1=s1.length();
        int size2=s2.length();
        vector<vector<int>>dp(size1+1,vector<int>(size2+1,0));
        for(int i=1;i<=size1;i++){
            for(int j=1;j<=size2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+(int)(s1[i-1]);
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int sum1=0;
        for(auto &d:s1){
            sum1+=(int)(d);
        }
        int sum2=0;
        for(auto &d:s2){
            sum2+=(int)(d);
        }

        return (sum1+sum2-(2*dp[size1][size2]));
    }
};