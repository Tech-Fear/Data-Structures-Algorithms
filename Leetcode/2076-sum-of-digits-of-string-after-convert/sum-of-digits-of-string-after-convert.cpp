class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(auto &ch:s){
            temp+=to_string((ch-'a')+1);
        }
        int ans=0;
        while(k--){
            ans=0;
            for(auto &t:temp){
                ans+=(t-'0');
            }
            temp=to_string(ans);
        }
        return ans;
    }
};