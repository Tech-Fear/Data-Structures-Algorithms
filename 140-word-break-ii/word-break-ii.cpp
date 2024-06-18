class Solution {
public:
    vector<string>ans;
    unordered_set<string>dict;
    void solve(string &s,int ind,string curr){
        if(ind==s.length()){
            ans.push_back(curr.substr(0,curr.length()-1));            
            return ;
        }
        for(int i=ind;i<s.length();i++){
            string sub=s.substr(ind,i-ind+1);
            if(dict.find(sub)!=dict.end()){
                string st=curr+sub+" ";
                solve(s,i+1,st);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &i:wordDict){
            dict.insert(i);
        }
        solve(s,0,"");
        return ans;
    }
};