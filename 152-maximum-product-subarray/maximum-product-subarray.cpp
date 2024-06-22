
class Solution {
public:
  int maxProduct(vector<int>& nums) {
       unordered_map<int,int>m;
        __int128_t sum=1;
          int maxi=INT_MIN;
       int neg=INT_MIN;
       for(int i=0;i<nums.size();i++){
          sum=sum*nums[i];
          if(sum>maxi){
          maxi=sum;
          }
           if(sum==0){
             sum=1;
             neg=INT_MIN;
           }
           if(sum<0){
            if(neg!=INT_MIN){
                if(sum/neg>maxi){
                  maxi=sum/neg;
              }
                 }
                 if(neg<sum){
                    neg=sum;
                 }
           }
          m[sum]++;
       }
    return maxi;
    }
};