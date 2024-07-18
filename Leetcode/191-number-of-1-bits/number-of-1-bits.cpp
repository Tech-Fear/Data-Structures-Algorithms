class Solution {
private:
    int countSetBits(int n){
        if(n==0) return 0;
        return 1+countSetBits(n&(n-1));
    }
public:
    int hammingWeight(int n) {
        // int ans=__builtin_popcount(n);
        int ans=countSetBits(n);
        return ans;
    }
};