class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> mp;
        int count = 0;
        for (const string& num : nums) {
            mp[num]++;
        }
        for (const string& num : nums) {
            int len = num.length();
            if (target.substr(0, len) == num) {
                string suffix = target.substr(len);
                if (mp.count(suffix)) {
                    count += mp[suffix];
                    if (suffix == num) count--;
                }
            }
        }

        return count;
    }
};
