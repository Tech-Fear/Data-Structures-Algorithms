class Solution {
public:
    static bool comp(int &a,int &b){
        string c=to_string(a);
        string d=to_string(b);
        return c<d;
    }
    void solve(int cur,int &n,vector<int>&ans){
        if(cur>n) return ;
        ans.push_back(cur);
        for(int i=0;i<10;i++){
            int j=cur*10+i;
            if(j<=n){
                solve(j,n,ans);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        //approch 1 Sorting T.C NLogN
        // vector<int>ans(n);
        // for(int i=0;i<n;i++) ans[i]=i+1;
        // sort(ans.begin(),ans.end(),comp);
        // return ans;
        

        //approch 2
        vector<int>ans;
        for(int i=1;i<=9;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};