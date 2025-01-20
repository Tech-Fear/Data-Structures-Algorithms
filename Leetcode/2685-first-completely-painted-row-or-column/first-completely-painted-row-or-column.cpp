class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        vector<int>row(r,0),col(c,0);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){ 
                mp[mat[i][j]].push_back(i);
                mp[mat[i][j]].push_back(j);
            }
        }
        for(int i=0;i<arr.size();i++){
            int ele=arr[i];
            if(mp.find(ele)!=mp.end()){
                vector<int>ar=mp[ele];
                row[ar[0]]+=1;
                col[ar[1]]+=1;
                if(row[ar[0]]==c || col[ar[1]]==r){
                    return i;
                }
            }
        }
        return -1;
    }
};