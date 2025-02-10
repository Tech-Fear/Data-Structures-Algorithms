class Solution {
public:
    string clearDigits(string s) {
        stack<char>stk;
        for(auto &i:s){
            if(!stk.empty() && (i-'0')<=9){
                stk.pop();
            }else{
                stk.push(i);
            }
        }
        string ans="";
        while(!stk.empty()){
            ans=(stk.top()+ans);
            stk.pop();
        }
        return ans;
    }
};