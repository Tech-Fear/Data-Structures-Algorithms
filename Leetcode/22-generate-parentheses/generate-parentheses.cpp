class Solution {
public:
    vector<string>ans;
    void generate(string st,int open,int close,int n){
        if(st.length()==2*n){
            ans.push_back(st);
            return;
        }
        if(open<n) generate(st+'(',open+1,close,n);
        if(open>close) generate(st+')',open,close+1,n); 
    }
    vector<string> generateParenthesis(int n) {
        generate("",0,0,n);
        return ans;
    }
};