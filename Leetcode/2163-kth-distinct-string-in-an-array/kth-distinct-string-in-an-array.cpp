class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp;
        for(auto &s:arr){
            mp[s]++;
        }
        vector<string>dist;
        for(auto &s:arr){
            if(mp[s]==1){
                dist.push_back(s);
            }
        }
        if(k>dist.size()){
            return "";
        }
        return dist[k-1];
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return "X";
}();