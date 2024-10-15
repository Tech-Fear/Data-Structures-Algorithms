class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        long long count0=0;
        for(char c:s){
            if(c=='0') ans+=count0;
            else count0++;
        }
        return ans;
    }
};