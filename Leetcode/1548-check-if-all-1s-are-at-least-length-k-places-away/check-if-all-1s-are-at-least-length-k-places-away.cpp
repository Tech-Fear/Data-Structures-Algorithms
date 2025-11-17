class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastPos = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (lastPos != -1 && i - lastPos <= k) {
                    return false;
                }
                lastPos = i;
            }
        }
        return true;
    }
};