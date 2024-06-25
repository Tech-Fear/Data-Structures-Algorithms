class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int maxUnsatisfiedCust=0;
        int curMaxUnsatiesfied=0;
        for(int i=0;i<minutes;i++){
            curMaxUnsatiesfied+=customers[i]*grumpy[i]; //can also be written in if condition like if(grumpy[i]==10) curMaxUnsatiesfied+=customers[i];
        }
        maxUnsatisfiedCust=curMaxUnsatiesfied;
        int i=0;
        int j=minutes;
        while(j<n){
            curMaxUnsatiesfied+=customers[j]*grumpy[j];
            curMaxUnsatiesfied-=customers[i]*grumpy[i];
            maxUnsatisfiedCust=max(maxUnsatisfiedCust,curMaxUnsatiesfied);
            i++;j++;
        }
        int totalSatiesfied=maxUnsatisfiedCust;
        for(i=0;i<n;i++){
            totalSatiesfied+=customers[i]*(!grumpy[i]);
        }
        return totalSatiesfied;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();