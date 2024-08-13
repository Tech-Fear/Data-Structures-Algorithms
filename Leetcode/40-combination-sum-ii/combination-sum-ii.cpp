class Solution {
private:
    void solve(vector<vector<int>>&ans,vector<int>&cur,vector<int>&candidates,int ind,int sum,int target){
        if(sum==target){
            ans.push_back(cur);
            return;
        }
        if(ind>=candidates.size() || sum+candidates[ind]>target) return;
        sum+=candidates[ind];
        cur.push_back(candidates[ind]);
        solve(ans,cur,candidates,ind+1,sum,target);
        sum-=candidates[ind];
        cur.pop_back();
        while(ind+1<candidates.size() && candidates[ind]==candidates[ind+1]) ind++;
        solve(ans,cur,candidates,ind+1,sum,target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        vector<int>cur;
        vector<vector<int>>ans;
        int ind=0;
        solve(ans,cur,candidates,ind,0,target);
        return ans;
    }
};