class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int len=0;
        if(k%2==0) return -1;
        int i=1;
        int n=1;
        unordered_set<int>st;
        while(i){
            int rem=n%k;
            if(rem==0) return i;
            if(st.find(rem)!=st.end()) return -1;
            st.insert(rem);
            n=rem*10+1;
            i++;
        }
        return -1;
    }
};