class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long ans=0;
        unordered_map<int,long long>mp;
        for(int i=0;i<hours.size();i++){
            int req=(24-hours[i]%24)%24;
            ans+=mp[req];
            mp[hours[i]%24]++;
        }
        return ans;
    }
};