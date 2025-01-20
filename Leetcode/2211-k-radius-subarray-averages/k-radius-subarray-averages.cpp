class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        vector<int>ans(n,-1);
        for(int i=k;i<n-k;i++){
            long long su=pref[i+k+1]-pref[i-k];
            su/=((2*k)+1);
            ans[i]=su;
        }
        return ans;
    }
};