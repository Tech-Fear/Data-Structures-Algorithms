class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0,r=n-1;
        sort(begin(citations),end(citations));
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int idx=n-mid;
            if(citations[mid]>=idx){
                ans=idx;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};