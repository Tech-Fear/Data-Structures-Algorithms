class Solution {
public:
    int digiSum(int num) {
        int s = 0;
        while (num > 0) {
            s += (num % 10);
            num /= 10;
        }
        return s;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        int ans = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            int dS = digiSum(nums[i]);
            
            if (mp.find(dS) != mp.end()) {
                if (nums[i] > mp[dS].first) {
                    mp[dS].second = mp[dS].first;
                    mp[dS].first = nums[i];
                } else if (nums[i] > mp[dS].second) {
                    mp[dS].second = nums[i];
                }
                if (mp[dS].second != -1) {
                    ans = max(ans, mp[dS].first + mp[dS].second);
                }
            } else {
                mp[dS] = {nums[i], -1};
            }
        }
        
        return ans;
    }
};
