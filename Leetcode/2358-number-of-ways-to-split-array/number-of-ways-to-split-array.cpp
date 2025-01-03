class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        vector<long long> preSum(n, 0);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        long long totalSum = preSum[n - 1];
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (preSum[i - 1] >= totalSum - preSum[i - 1]) {
                count++;
            }
        }
        return count;
    }
};
