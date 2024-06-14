class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>cur;
        find_sub(0,cur,nums,target);
        return res;
    }
    void find_sub(int ind,vector<int>&cur,vector<int>&nums,int target){
        if(target==0){
            res.push_back(cur);
            return;
        }
        if(ind==nums.size() || target<0) return;
        //case 1 include
        cur.push_back(nums[ind]);
        find_sub(ind,cur,nums,target-nums[ind]);
        cur.pop_back();
        find_sub(ind+1,cur,nums,target);
    }
};