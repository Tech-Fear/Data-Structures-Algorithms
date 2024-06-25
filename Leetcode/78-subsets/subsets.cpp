class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curs;
        generate(0,curs,nums,res);
        return res;
    }
    void generate(int ind,vector<int>&curs,vector<int>&nums,vector<vector<int>>&res){
        if(ind==nums.size()){
            res.push_back(curs);
            return;
        }
        generate(ind+1,curs,nums,res);
        curs.push_back(nums[ind]);
        generate(ind+1,curs,nums,res);
        curs.pop_back();
    }
};