class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3) return nums.size();
        int ind=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[ind-2]){
                nums[ind]=nums[i];
                ind++;
            }
        }
        return ind;
    }
};