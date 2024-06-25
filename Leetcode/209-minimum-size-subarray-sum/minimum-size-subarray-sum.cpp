class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int left=0,right=0,sum=0;
        int n=nums.size();
        while(left<n || right<n ){
            if(sum<target && right<n){
                sum+=nums[right];
                right++;
            }else if(sum>=target && left<n){
                ans=min(ans,right-left);
                sum-=nums[left];
                left++;
            }else break;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};