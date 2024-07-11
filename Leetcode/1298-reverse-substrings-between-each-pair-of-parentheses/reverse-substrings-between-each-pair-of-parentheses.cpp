class Solution {
public:
    string reverseParentheses(string s) {
        string str,rev;
        for(char c:s){
            if(c!=')') str.push_back(c);
            else{
                rev="";
                char r=str.back();
                while(r!='('){
                    rev+=r;
                    str.pop_back();
                    r=str.back();
                }
                str.pop_back();
                str+=rev;
            }
        }
        return str;
    }
};