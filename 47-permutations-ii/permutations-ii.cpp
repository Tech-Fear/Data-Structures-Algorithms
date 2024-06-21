class Solution {
public:
    set<vector<int>>st;
    void solve(vector<int>& cur, vector<int>& nums, unordered_map<int, int>& freq) {
        if (cur.size() == nums.size()) {
            st.insert(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (freq[nums[i]] > 0) {
                freq[nums[i]]--;
                cur.push_back(nums[i]);
                solve(cur, nums, freq);
                freq[nums[i]]++;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> cur;
        vector<vector<int>> ans;
        for (auto num : nums) {
            freq[num]++;
        }
        solve(cur, nums, freq);
        for(auto &i:st){
            ans.push_back(i);
        }
        return ans;
    }
};
auto init=[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();