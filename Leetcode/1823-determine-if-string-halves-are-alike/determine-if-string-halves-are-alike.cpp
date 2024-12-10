class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int s2=n/2;
        int countVow=0;
        set<char>st={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0;i<n/2;i++){
            if(st.find(s[i])!=st.end()){
                countVow++;
            }
            if(st.find(s[s2+i])!=st.end()){
                countVow--;
            }
        }
        return countVow==0;
    }
};