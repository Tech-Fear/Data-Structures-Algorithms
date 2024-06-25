class Solution {
public:
    long long  hours(vector<int> &arr,int mid){
        long long hou=0;
        for(int i=0;i<arr.size();i++){
            hou+=ceil(arr[i]/(double)mid);
        }
        return hou;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,hi=*max_element(piles.begin(),piles.end());
        while(l<=hi){
            long long mid=l+(hi-l)/2;
            long long ho=hours(piles,mid);
            if(ho>h){
                l=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return l;
    }
};