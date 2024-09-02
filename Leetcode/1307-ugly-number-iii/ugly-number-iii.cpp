class Solution {
public:
    long long lcm(long long a,long long b){
        return a*b/gcd(a,b);
    }
    long long gcd(long long a,long long b){
        return b==0?a:gcd(b,a%b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab=lcm(a,b);
        long long ac=lcm(a,c);
        long long bc=lcm(b,c);
        long long abc=lcm(ab,c);
        long long l=1,r=2e9;
        while(l<r){
            long long mid=(l+r)/2;
            if(mid/a+mid/b+mid/c-mid/ab-mid/bc-mid/ac+mid/abc >=n){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return (int)l;

    }
    
};