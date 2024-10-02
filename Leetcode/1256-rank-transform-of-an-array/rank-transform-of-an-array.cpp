class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int>arr2=arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>ranks;
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        for(int i=0;i<arr.size();i++){
            ranks[arr[i]]=i+1;
        }
        for(int i=0;i<arr2.size();i++){
            arr2[i]=ranks[arr2[i]];
        }
        return arr2;
    }
};