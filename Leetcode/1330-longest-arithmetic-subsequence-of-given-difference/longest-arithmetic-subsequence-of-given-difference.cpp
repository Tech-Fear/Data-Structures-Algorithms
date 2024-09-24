class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int>mp;
        vector<int>dp(n);
        int ans=0;
        for(int i=0;i<n;i++){
            int num=arr[i]-difference;
            if(mp.count(num)){
                dp[i]=dp[mp[num]]+1;
            }else{
                dp[i]=1;
            }
            mp[arr[i]]=i;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};