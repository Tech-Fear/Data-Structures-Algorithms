class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int prLen=pref.length();
        for(auto &word:words){
            int n=word.length();
            if(n<prLen) continue;
            string sub=word.substr(0,prLen);
            if(sub==pref) count++;
        }
        return count;
    }
};