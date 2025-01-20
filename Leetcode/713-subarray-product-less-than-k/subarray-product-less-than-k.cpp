class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        long long mul=1;
        int n=nums.size();
        int ans=0;
        while(r<n){
            mul*=nums[r];
            while(l<=r && mul>=k){
                mul/=nums[l++];
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};