class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=accumulate(gas.begin(),gas.end(),0);
        int totalCost=accumulate(cost.begin(),cost.end(),0);
        if(totalGas<totalCost) return -1;
        int startInd=0,curGas=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            curGas+=gas[i]-cost[i];
            if(curGas<0){
                curGas=0;
                startInd=i+1;
            }
        }
        return startInd;
    }
};