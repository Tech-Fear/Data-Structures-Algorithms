class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; ++i){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }  
        for(int i = 0; i < n; ++i){
            int leftSum;
            if(i == 0){
                leftSum = 0;
            }else{
                leftSum = prefixSum[i - 1];
            }
            int rightSum = prefixSum[n - 1] - prefixSum[i];
            if (leftSum == rightSum){
                return i;
            }
        }
        
        return -1;
    }
};