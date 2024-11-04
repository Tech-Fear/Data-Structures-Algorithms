class Solution {
public:
    string compressedString(string word) {
        string ans="";
        for(int i=0;i<word.length();i++){
            char c=word[i];
            int count=1;
            while(i+1<word.length() && c==word[i+1] && count<9){
                count++;
                i++;
            }
            ans+=to_string(count) + c;
        }
        return ans;
    }
};