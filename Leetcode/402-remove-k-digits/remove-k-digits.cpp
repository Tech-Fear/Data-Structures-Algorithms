class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        if(k>=n) return "0";
        vector<char>ans;
        for(int i=0;i<n;i++){
            while(k>0 && !ans.empty() && ans.back()>num[i]){
                k--;
                ans.pop_back();
            }
            ans.push_back(num[i]);
        }
        while(k>0 && !ans.empty()){
            k--;
            ans.pop_back();
        }
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        string res = (i == ans.size()) ? "0" : string(ans.begin() + i, ans.end());
        return res;
    }
};