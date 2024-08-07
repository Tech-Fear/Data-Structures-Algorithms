class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int currSum=0;
        for(int i=0;i<n;i++){
            if((total-currSum-nums[i])==currSum){
                return i;
            }
            currSum+=nums[i];
        }
        return -1;
    }
};