class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string>strings;
        stringstream ss(sentence);
        string s;
        while(ss>>s){
            strings.push_back(s);
        }
        int n=strings.size();
        for(int i=0;i<strings.size();i++){
            char s1=strings[i][strings[i].length()-1];
            char s2=strings[(i+1)%n][0];
            if(s1!=s2) return false;
        }
        return true;
    }
};