class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>stk;
        vector<bool>temp(s.length(),false);
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push(i);
            }else if(s[i]==')'){
                if(!stk.empty()){
                    stk.pop();
                }else{
                    temp[i]=true;
                }
            }
        }
        while(!stk.empty()){
            temp[stk.top()]=true;
            stk.pop();
        }
        string ans="";
        for(int i = 0;i<s.length();i++){
            if(!temp[i]){
                ans+=s[i];
            }
        }
        return ans;
    }
};