class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        unordered_map<int,int>mp2;
        for(auto &x:mp){
            mp2[x.second]++;
            if(mp2[x.second]>1) return false;
        }
        return true;
    }
};