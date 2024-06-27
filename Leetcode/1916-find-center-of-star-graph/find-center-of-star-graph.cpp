class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // unordered_map<int,int>deg;
        // for(auto &e:edges){
        //     deg[e[0]]++;
        //     deg[e[1]]++;
        // }
        // int size=edges.size();
        // int ans=-1;
        // for(auto &mp:deg){
        //     if(mp.second==size){
        //         ans=mp.first;
        //         break;
        //     }
        // }
        // return ans;
        int ans=-1;
        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]) ans=edges[0][0];
        if(edges[0][1]==edges[1][0] || edges[0][1]==edges[1][1]) ans=edges[0][1];
        return ans;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return '!';
}();