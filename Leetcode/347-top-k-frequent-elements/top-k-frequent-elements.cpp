class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> arr(n + 1);
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto& freq : mp) {
            arr[freq.second].push_back(freq.first);
        }
        for (int i = n; i >= 0 && ans.size() < k; --i) {
            if (!arr[i].empty()) {
                for (int num : arr[i]) {
                    ans.push_back(num);
                    if (ans.size() == k) {
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};