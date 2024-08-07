class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        int count=0;
        for(auto &t:time){
            int rem=(t%60);
            int c=(60-rem)%60;
            if(mp.find(c)!=mp.end()){
                count+=mp[c];
            }
            mp[rem]++;
        }
        return count;
    }
};