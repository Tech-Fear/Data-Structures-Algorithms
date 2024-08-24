class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int ans=0;
        int count=0;
       for(int i=0;i<n;i++){
            if(nums[i]==0){ ans=max(ans,count);
                count=0;
            }
            else{
                count++;
            }
       }
       ans=max(ans,count);
        return ans;
    }
};