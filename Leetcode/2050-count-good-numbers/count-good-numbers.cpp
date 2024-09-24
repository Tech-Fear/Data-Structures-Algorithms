class Solution {
public:
    int mod=1e9+7;
    long long power(long long a,long long b){
        if(b==0){
            return 1;
        }
        // if(b==1) return a%mod;
        long long res=power(a,b/2);
        if(b%2==0){
            return ((res%mod)*(res%mod))%mod;
        }
        return  ((((res%mod)*(res%mod))%mod)*(a%mod));
    }
    int countGoodNumbers(long long n) {
        // long long ans=1;
        long long pow5;
        long long pow4;
        if(n%2==0){
            pow5=power(5,n/2);
            pow4=power(4,n/2);
        }else{
            long long x=n/2;
            pow5=power(5,x+1);
            pow4=power(4,x);
        }
        int ans=((pow5%mod)*(pow4%mod))%mod;
        return ans;
    }
};