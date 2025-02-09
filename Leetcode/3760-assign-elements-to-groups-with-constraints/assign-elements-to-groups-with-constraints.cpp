class Solution {
public:
    void check(int n,unordered_map<int,int>&m,vector<int>&ans){
        int k=INT_MAX;
        for(int i=1;i*i<=n;i++){
            if(n%i==0 && m.count(i)){
                k=min(k,m[i]);
            }
            if(i!=n/i && n%i==0 && m.count(n/i)){
                k=min(k,m[n/i]);
            }
        }
        ans.push_back(k==INT_MAX?-1:k);
    }
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int,int>mp;
        for(int i=0;i<elements.size();i++){
            if(mp.count(elements[i])==0) mp[elements[i]]=i;
        }
        vector<int>ans;
        for(int i=0;i<groups.size();i++){
            check(groups[i],mp,ans);
        }
        return ans;
    }
};