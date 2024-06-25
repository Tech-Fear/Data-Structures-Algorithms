class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int size=arr.size();
        if(n==0) return true;
        if (size == 1) return (arr[0] == 0 && n <= 1);
        for(int i=0;i<size && n>0;i++){
            if(arr[i]==0){
                bool left=(i==0 || arr[i-1]==0);
                bool right=(i==size-1 || arr[i+1]==0);
                if(left && right){
                    n--;
                    arr[i]=1;
                }
            }
        }
        return n==0;
    }
};