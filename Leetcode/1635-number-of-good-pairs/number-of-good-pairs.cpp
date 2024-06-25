class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // int count = 0;
        // unordered_map<int,int>ans;
        // for(int i=0;i<nums.size();i++)
        // {
        //     ans[nums[i]]++;
        // }
        
        // for(auto it: ans)
        // {
        //     int val = it.second;
        //     count = count + (val*(val-1))/2;
        // }
        // return count;
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) cnt += 1;
            }
        }
        return cnt;
    }
};