class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign = true;
        if((dividend>=0 && divisor<0) || (dividend<=0 && divisor>0)) sign = false;
        int count=0;
        long long n = abs(dividend);
        long long d = abs(divisor);
        long long quotient=0;
        divisor=abs(divisor);
        while(n>=d){
            int count=0;
            while(n>=(d<<count+1)){
                count+=1;
            }
            quotient+=(1<<count);
            n-=(d<<count);
        } 
        if(quotient==(1<<31) && sign) return INT_MAX;

        if(quotient ==(1<<31) && !sign) return INT_MIN;

        return sign ? quotient:-quotient;
    }
};