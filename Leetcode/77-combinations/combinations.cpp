class Solution {
private:
    void solve(vector<vector<int>>&ans,vector<int>&cur,int ind,int k,int n){
        if(k==cur.size()){
            ans.push_back(cur);
            return;
        }
        if(ind>n) return;
        cur.push_back(ind);
        solve(ans,cur,ind+1,k,n);
        cur.pop_back();
        solve(ans,cur,ind+1,k,n);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>cur;
        solve(ans,cur,1,k,n);
        return ans;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'X';
}();