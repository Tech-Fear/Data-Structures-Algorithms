class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        int closingNotMatched=0;
        for(char &ch:s){
            if(ch=='('){
                stk.push(ch);
            }else{
                if(stk.empty()){
                    closingNotMatched++;
                }
                else stk.pop();
            }
        }
        return stk.size()+closingNotMatched;
    }
};