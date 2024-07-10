class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            auto it =mp.find(nums[i]);
            if(it!=mp.end() && abs(i-it->second)<=k) return true;
            mp[nums[i]]=i;
        }
        return false;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'E';
}();