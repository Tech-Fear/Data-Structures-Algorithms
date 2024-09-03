class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>temp(numRows);
        int curRow=0;
        bool dirD=false;
        if(numRows==1) return s;
        for(int i=0;i<s.size();i++){
            temp[curRow]+=s[i];
            if(curRow==0|| curRow==numRows-1){
                dirD=!dirD;
            }
            curRow+=dirD?1:-1;
        }
        string ans="";
        for(auto &t:temp){
            ans+=t;
        }
        return ans;
    }
};