class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<hours.size();i++){
            int req=(24-hours[i]%24)%24;
            ans+=mp[req];
            mp[hours[i]%24]++;
        }
        return ans;
    }
};