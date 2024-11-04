class Solution {
public:
    string compressedString(string word) {
        vector<char>ans;
        for(int i=0;i<word.length();i++){
            char c=word[i];
            int count=1;
            while(i+1<word.length() && c==word[i+1] && count<9){
                count++;
                i++;
            }
            ans.push_back(count+'0');
            ans.push_back(c);
        }
        return string(ans.begin(),ans.end());
    }
};