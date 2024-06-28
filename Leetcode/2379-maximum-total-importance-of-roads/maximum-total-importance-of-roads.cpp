class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long totalImp=0;
        map<long long,long long>mp;
        multiset<long long>st;
        for(auto &road:roads){
            mp[road[0]]++;
            mp[road[1]]++;
        }
        for(auto &m:mp){
            st.insert(m.second);
        }

        for(auto it=st.rbegin();it!=st.rend();it++){
            totalImp+=(*it * n);
            n--;
        }

        return totalImp;
    }
};
auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '#';
}();