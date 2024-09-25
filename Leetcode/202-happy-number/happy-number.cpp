class Solution {
public:
    int numSq(int n){
        int s=0;
        while(n>0){
            int t=n%10;
            s+=t*t;
            n/=10;
        }
        return s;
    }
    bool isHappy(int n) {
        int s=0;
        while(n!=1){
            s=numSq(n);
            n=s;
            s=0;
            if(n==4) return 0;
        }
        return 1;
    }
};