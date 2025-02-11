class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long>sps;
        sps.insert(0);
        long long curSum=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            curSum+=nums[i];
            auto low=sps.lower_bound(curSum-upper);
            auto up=sps.upper_bound(curSum-lower);
            ans+=distance(low,up);
            sps.insert(curSum);
        }
        return ans;
    }
};