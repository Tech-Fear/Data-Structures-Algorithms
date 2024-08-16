class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int xMin=arrays[0][0],Xmax=arrays[0].back();
        int diff=0;
        int m=arrays.size();
        for(int i=1;i<m;i++){
            vector<int>arr=arrays[i];
            int a0=arr[0],aN=arr.back();
            diff=max(diff,max(aN-xMin,Xmax-a0));
            xMin=min(a0,xMin);
            Xmax=max(aN,Xmax);
        }
        return diff;
    }
};