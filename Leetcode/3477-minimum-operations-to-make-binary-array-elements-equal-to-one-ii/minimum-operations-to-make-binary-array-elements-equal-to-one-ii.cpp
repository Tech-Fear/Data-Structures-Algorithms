class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                count++;
            }
        }
        if (nums[0] == 0) {
            count++;
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
