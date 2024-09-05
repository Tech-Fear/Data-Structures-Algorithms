class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[&](vector<int>&p1,vector<int>&p2){
            return p1[1]<p2[1];
        });
        int chainLength=0;
        int cur_end=INT_MIN;
        for(auto &p:pairs){
            if(p[0]>cur_end){
                chainLength++;
                cur_end=p[1];
            }
        }
        return chainLength;
    }
};