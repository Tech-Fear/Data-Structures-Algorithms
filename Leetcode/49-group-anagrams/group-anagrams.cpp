class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto &s:strs){
            string w=s;
            sort(w.begin(),w.end());
            mp[w].push_back(s);
        }
        for(auto &m:mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'X';
}();