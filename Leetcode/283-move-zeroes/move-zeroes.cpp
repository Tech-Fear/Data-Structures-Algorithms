class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int count=0,right=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0 && nums[left]==0){
                swap(nums[i],nums[left]);
                left++;
            }else if(nums[left]!=0) left++;
        }
    }
};