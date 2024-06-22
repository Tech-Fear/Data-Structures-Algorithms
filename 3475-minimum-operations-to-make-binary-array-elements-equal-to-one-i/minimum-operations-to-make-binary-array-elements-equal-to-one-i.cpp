class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i <= n - 3; ++i) {
        if (nums[i] == 0) {
            for (int j = 0; j < 3; ++j) {
                nums[i + j] = 1 - nums[i + j];
            }
            count++;
        }
    }
    if (nums[n - 2] == 0 || nums[n - 1] == 0) {
        return -1;
    }

    return count;
    }
};
auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return '$';
}();