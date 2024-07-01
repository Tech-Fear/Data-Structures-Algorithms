class Solution {
public:
    string simplifyPath(string path) {
        string res;
        stack<string>st;
        int n=path.length();
        for(int i=0;i<n;i++){
            if(path[i]=='/') continue;
            string temp;
            while(i<n && path[i]!='/'){
                temp+=path[i++];
            }
            if(temp==".." ) {
                if(!st.empty())
                    st.pop();
                continue;
            }
            else if(temp==".") continue;
            else st.push(temp);
        }
        while(!st.empty()){
            res="/"+st.top()+res;
            st.pop();
        }
        return res.empty() ? "/" : res;
    }
};