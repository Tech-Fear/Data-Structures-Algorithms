class Solution {
public:
void merge(vector<int>& arr,int low,int mid,int high){
    int left=mid-low+1;
    int right=high-mid;
    int larr[left];
    int rarr[right];
    for(int i=0;i<left;i++){
        larr[i]=arr[low+i];
    }
    for(int i=0;i<right;i++){
        rarr[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=low;
    while(i<left && j<right){
        if(larr[i]<=rarr[j]){
            arr[k++]=larr[i++];
        }else{
            arr[k++]=rarr[j++];
        }
    }
    while(i<left){
        arr[k++]=larr[i++];
    }
    while(j<right) arr[k++]=rarr[j++];
}
    void mergeSort(vector<int>&array,int begin , int end ){
        if(begin>=end) return;
        int mid= begin+(end-begin)/2;
        mergeSort(array,begin,mid);
        mergeSort(array,mid+1,end);
        merge(array,begin,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();
        mergeSort(nums,0,size-1);
        return nums;
    }
};