class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool flag1 = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                flag1 = true;
            }
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }
        if (!flag1) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
