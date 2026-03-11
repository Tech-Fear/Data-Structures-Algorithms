class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t size = nums.size();
        vector<int> ans(size);
        ans[0] = 1;
        // pre
        for (int i = 1; i < size; i++) {
            ans[i] = ans[i-1] * nums[i - 1];
        }

        // suf
        int suf = 1;
        for (int i = size - 1; i >= 0; i--) {
            ans[i] *= suf;
            suf *= nums[i];
        } 
        return ans;
    }
};