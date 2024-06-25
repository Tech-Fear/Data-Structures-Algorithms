#define ll long long
class Solution {
public:
    bool judgeSquareSum(int c) {
        int low=0,high=sqrt(c);
        while(low<=high){
            ll a=low*low,b=high*high;
            if(a+b==c) return 1;
            if(a+b>c) high--;
            else low++;
        }
        return 0;
    }
};