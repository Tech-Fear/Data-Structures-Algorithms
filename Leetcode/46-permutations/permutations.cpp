class Solution {
public:
    vector<vector<int>>ans;
    void generate(vector<bool>&taken,vector<int>&cur,vector<int>&nums){
        if(cur.size()==nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!taken[i]){
                cur.push_back(nums[i]);
                taken[i]=true;
                generate(taken,cur,nums);
                taken[i]=false;
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>cur;
        vector<bool>taken(nums.size(),false);
        generate(taken,cur,nums);
        return ans;
    }
};