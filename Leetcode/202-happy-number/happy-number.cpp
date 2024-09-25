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
        int s=numSq(n);
        int f=numSq(numSq(n));
        while(s!=f && f!=1){
            s=numSq(s);
            f=numSq(numSq(f));
        }
        return f==1;
    }
};