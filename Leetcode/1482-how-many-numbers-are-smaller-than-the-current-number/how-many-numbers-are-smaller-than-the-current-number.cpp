class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>countNum(101);
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        int prevCount = 0;
        for(int i=0;i<101;i++){
            int curFreq = freq.find(i)!=freq.end()? freq[i]:0;
            countNum[i] = prevCount;
            prevCount += curFreq;
        }
        vector<int>ans;
        for(auto num:nums){
            ans.push_back(countNum[num]);
        }
        return ans;
    }
};