typedef vector<int> v32;
typedef vector<v32> vv32;
class Solution {
    int solve(v32 &stones,int i,int total,int &target,vv32 &dp,int &sum){
        if(target<=total || i>=stones.size()){
            return abs(total-(sum-total));
        }
        if(dp[i][total]!=-1) return dp[i][total];
        dp[i][total]=min(solve(stones,i+1,total+stones[i],target,dp,sum),solve(stones,i+1,total,target,dp,sum));
        return dp[i][total];
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        int target=ceil(sum/2);
        vector<vector<int>>dp(stones.size(),vector<int>(target+1,-1));
        return solve(stones,0,0,target,dp,sum);
    }
};