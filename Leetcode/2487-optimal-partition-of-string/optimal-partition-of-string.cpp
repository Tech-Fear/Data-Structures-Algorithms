class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            unordered_set<char>st;
            string temp="";
            while(i<n && st.find(s[i])==st.end()){
                temp+=s[i];
                st.insert(s[i]);
                i++;
            }
            i--;
            ans.push_back(temp);
        }
        return ans.size();
    }
};