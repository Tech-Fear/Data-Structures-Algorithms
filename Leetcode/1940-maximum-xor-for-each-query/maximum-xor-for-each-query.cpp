class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ans;
        int XOR=0;
        for(auto num:nums){
            XOR^=num;
        }
        int mask=(1<<maximumBit)-1;
        for(int i=nums.size()-1;i>=0;i--){
            ans.push_back(XOR^mask);
            XOR^=nums[i];
        }
        return ans;
    }
};