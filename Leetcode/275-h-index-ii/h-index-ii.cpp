class Solution {
public:
    int hIndex(vector<int>& citations) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=citations.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(citations[mid]<(n-mid)){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return n-low;
    }
};