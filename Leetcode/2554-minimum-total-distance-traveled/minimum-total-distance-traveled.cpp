class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<long long>dp(robot.size()+1,LLONG_MAX);
        int m=factory.size();
        dp[0]=0;
        for(auto &fact:factory){
            int cap=fact[1];
            int position=fact[0];
            vector<long long>new_dp(dp);
            for(int i=0;i<robot.size();i++){
                long long dist=0;
                for(int k=1;k<=cap && i+k<=robot.size();k++){
                    dist+=abs(robot[i+k-1]-position);
                    if(dp[i]==LLONG_MAX){
                        continue;
                    }
                    new_dp[i+k]=min(dist+dp[i],new_dp[i+k]);
                }
            }
            dp=new_dp;
        }
        return dp[robot.size()];
    }
};