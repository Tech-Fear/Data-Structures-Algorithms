class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int baseState=minutesToTest/minutesToDie;
        baseState+=1;
        int res=0,p=1;
        while(p<buckets){
            p*=baseState;
            res++;
        }
        return res;
    }
};