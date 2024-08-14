class Solution {
private:
    static bool comp(string &a,string &b){
        return a.length()<b.length();
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end(),comp);
        string ans=strs[0];
        for(string &st:strs){
            string temp="";
            int minLength=min(st.length(),ans.length());
            for(int i=0;i<minLength;i++){
                if(ans[i]!=st[i]) break;
                temp+=st[i];
            }
            ans=temp;
        }
        return ans;
    }
};