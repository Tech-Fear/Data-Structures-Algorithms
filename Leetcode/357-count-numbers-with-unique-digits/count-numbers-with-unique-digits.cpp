class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int res=10,unique=9,avial=9;
        while(n-->1 && avial>0){
            unique*=avial;
            res+=unique;
            avial--;
        }
        return res;
    }
};