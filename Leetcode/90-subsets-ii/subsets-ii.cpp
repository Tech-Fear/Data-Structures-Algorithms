class Solution {
private:
    void generateSubset(vector<int>&nums,int ind,vector<int>&cur,vector<vector<int>>&ans){
        ans.push_back(cur);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            cur.push_back(nums[i]);
            generateSubset(nums,i+1,cur,ans);
            cur.pop_back();
        } 
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int>cur;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        generateSubset(nums,0,cur,ans);
        return ans;
    }

};