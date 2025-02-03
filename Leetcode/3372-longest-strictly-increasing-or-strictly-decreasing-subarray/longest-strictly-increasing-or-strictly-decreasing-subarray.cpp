class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int len = 1;
        int inc_len = 1, dec_len = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc_len++;
            } else {
                inc_len = 1;
            }

            if (nums[i] < nums[i - 1]) {
                dec_len++;
            } else {
                dec_len = 1;
            }

            len = max(len, max(inc_len, dec_len));
        }
        
        return len;
    }
};
