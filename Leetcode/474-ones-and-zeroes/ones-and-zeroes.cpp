class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<int> a(size), b(size);
        for(int i =0; i< size;i++){
            int c1= 0, c0=0;
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j] == '1'){
                    c1+=1;
                }else{
                    c0+=1;
                }
            }
            a[i] = c0;
            b[i] = c1;
        }

        return maxSubset(a,b,m,n);
    }
    int maxSubset(vector<int>& a, vector<int>& b, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int len = a.size();
        for (int i = 0; i < len; i++) {
            for (int sa = m; sa >= a[i]; sa--) {
                for (int sb = n; sb >= b[i]; sb--) {
                    dp[sa][sb] = max(dp[sa][sb], dp[sa - a[i]][sb - b[i]] + 1);
                }
            }
        }

        int ans = 0;
        for (int sa = 0; sa <= m; sa++)
            for (int sb = 0; sb <= n; sb++)
                ans = max(ans, dp[sa][sb]);

        return ans;
    }
};