class Solution {
public: 
    bool checkBloom(vector<int>&bloomDay,int &m,int &k,int &mid){
        int count=0;
        int j=0;
        for(int i:bloomDay){
            if(i<=mid){
                j++;
                if(j==k){
                    count++;
                    j=0;
                }
            }else{
                j=0;
            }
        }
        return count>=m;
    }
    int binarySearch(vector<int>&bloomDay,int &m,int &k){
        int ans=-1;
        int l=0,h=*max_element(bloomDay.begin(),bloomDay.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(checkBloom(bloomDay,m,k,mid)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        return binarySearch(bloomDay,m,k);
    }
};