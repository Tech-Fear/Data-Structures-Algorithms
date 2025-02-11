#define vp vector<pair<int,int>>
#define vi vector<int>
class Solution {
public:
    void merge(int l,int mid,int r,vp &arr,vi &ans){
        vp temp(r-l+1);
        int i=l;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=r){
            if(arr[i].first<=arr[j].first){
                temp[k++]=arr[j++];
            }else{
                ans[arr[i].second]+=(r-j)+1;
                temp[k++]=arr[i++];
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=r){
            temp[k++]=arr[j++];
        }
        for(int le=l;le<=r;le++){
            arr[le]=temp[le-l];
        }
    }
    void mergeSort(int l,int r,vp &arr,vi &ans){
        if(l>=r){
            return;
        }
        int mid=l+(r-l)/2;
        mergeSort(l,mid,arr,ans);
        mergeSort(mid+1,r,arr,ans);
        merge(l,mid,r,arr,ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vp arr;
        vi ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        mergeSort(0,nums.size()-1,arr,ans);
        return ans;
    }
};