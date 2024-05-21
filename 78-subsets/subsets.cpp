class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int size=nums.size();
        int subsetSize=1<<size;
        for(int i=0;i<subsetSize;i++){
            vector<int>subset;
            for(int j=0;j<size;j++){
                if(i & (1<<j)){
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};