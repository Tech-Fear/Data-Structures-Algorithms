class Solution {
public:
    vector<vector<string>>ans;
    bool check(string &str){
        int n=str.length();
        int s=0,e=n-1;
        while(s<=e){
            if(str[s]!=str[e]){
                return false;
            }
            s++;e--;
        }
        return true;
    }
    void solve(int ind,int &n,vector<string>&str,const string &s){
        if(ind==n){
            ans.push_back(str);
            return;
        }
        for(int i=ind;i<n;i++){
            string st=s.substr(ind,i-ind+1);
            if(check(st)){
                str.push_back(st);
                solve(i+1,n,str,s);
                str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>st;
        int n=s.size();
        solve(0,n,st,s);
        return ans;
    }
};