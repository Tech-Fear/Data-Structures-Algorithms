class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<long long,int>mp;
        long long preSum=0;
        int count=0;
        mp[0]=1;
        for(int i:nums){
            preSum+=i;
            int remove=preSum-k;
            count+=mp[remove];
            mp[preSum]++;
        }
        return count;
    }
};