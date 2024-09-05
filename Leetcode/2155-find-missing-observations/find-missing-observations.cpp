class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        long long total=mean*(n+m);
        long long rollsSum=0;
        for(int i=0;i<m;i++){
            rollsSum+=rolls[i];
        }
        long long rem=total-rollsSum;
        if(rem<n || rem>6*n){
            return {};
        }
        vector<int>ans(n,1);
        rem-=n;
        for(int i=0;i<n && rem>0;i++){
            int add=min(5LL,rem);
            ans[i]+=add;
            rem-=add;
        }
        return ans;
    }
};