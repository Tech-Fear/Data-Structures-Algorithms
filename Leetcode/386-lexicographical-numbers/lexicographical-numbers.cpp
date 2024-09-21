class Solution {
public:
    static bool comp(int &a,int &b){
        string c=to_string(a);
        string d=to_string(b);
        return c<d;
    }
    vector<int> lexicalOrder(int n) {
        //approch 1 Sorting T.C NLogN
        vector<int>ans(n);
        for(int i=0;i<n;i++) ans[i]=i+1;
        sort(ans.begin(),ans.end(),comp);
        return ans;
    }
};