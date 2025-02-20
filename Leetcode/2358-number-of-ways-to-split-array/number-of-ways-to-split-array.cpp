class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>pref(nums.size()+1,0);
        int n=nums.size();
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+nums[i-1];
        }
        int count=0;
        for(int i=1;i<n;i++){
            long long l=pref[i];
            long long r=pref[n]-l;
            if(r<=l) count++;
        }
        return count;
    }
};