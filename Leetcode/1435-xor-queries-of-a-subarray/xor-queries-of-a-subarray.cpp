class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>Xor(arr.size());
        int n=arr.size();
        int x=0;
        for(int i=0;i<n;i++){
            Xor[i]=x^arr[i];
            x^=arr[i];
        }
        vector<int>ans;
        for(auto &q:queries){
            int left=q[0];
            int right=q[1];
            if(left==0){
                ans.push_back(Xor[right]);
            }else{
                ans.push_back(Xor[right]^Xor[left-1]);
            }
        }
        return ans;
    }
};