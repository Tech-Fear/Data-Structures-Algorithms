class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int len=0,maxLen=0;
        for(auto &num:nums){
            if(num!=maxi){
                len=0;
                continue;
            }
            len++;
            maxLen=max(maxLen,len);
        }
        return maxLen;
    }
};