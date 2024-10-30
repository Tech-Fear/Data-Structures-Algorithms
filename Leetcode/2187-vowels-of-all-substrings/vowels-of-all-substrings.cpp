class Solution {
public:
    long long countVowels(string word) {
        long long ans=0;
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        long long n=word.size();
        for(long long i=0;i<n;i++){
            long long cur=0;
            if(st.find(word[i])!=st.end()){
                cur=(i+1)*(n-i);
                ans+=cur;
            }
        }
        return ans;
    }
};