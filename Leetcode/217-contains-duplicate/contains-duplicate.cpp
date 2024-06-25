#pragma GCC optimize("Ofast,unroll-loops")
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++){
        if(mp.find(nums[i])!=mp.end()){
            return true;
        }
        mp[nums[i]]++;
      }
      return false; 
    }
};
