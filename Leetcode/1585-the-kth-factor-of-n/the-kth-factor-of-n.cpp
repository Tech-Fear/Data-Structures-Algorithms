class Solution {
public:
    int kthFactor(int n, int k) {
        set<int>st;
        int i=1;
        while(i*i<=n){
            if(n%i==0){
                st.insert(i);
                st.insert(n/i);
            }
            i++;
        }
        int count=0;
        for(auto &t:st){
            count++;
            if(count==k){
                return t;
            }
        }
        return -1;
    }
};