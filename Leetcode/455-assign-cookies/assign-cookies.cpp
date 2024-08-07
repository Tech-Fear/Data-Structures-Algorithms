class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0,r=0;
        int gS=g.size(),sS=s.size();
        int count=0;
        while(l<gS && r<sS){
            if(g[l]<=s[r]){
                l++,r++,count++;
            }else{
                r++;
            }
        }
        return count;
    }
};