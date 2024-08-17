class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        set<string>s1;
        s1.insert("+");
        s1.insert("-");
        s1.insert("/");
        s1.insert("*");
        for(auto &to:tokens){
            if(s1.find(to)!=s1.end()){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                if(to=="+"){
                    st.push(num1+num2);
                }
                if(to=="-"){
                    st.push(num1-num2);
                }
                if(to=="/"){
                    st.push(num1/num2);
                }
                if(to=="*"){
                    st.push(num1*num2);
                }
            }else{
                st.push(stoi(to));
            }
        }
        return st.top();
    }
};