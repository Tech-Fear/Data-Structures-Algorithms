class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int ans=0;
        while(r<n){
            if(nums[r]==0){
                r+=1;
                l=r;
            }else{
                ans=max(ans,r-l+1);
                r++;
            }
        }
        return ans;
    }
};