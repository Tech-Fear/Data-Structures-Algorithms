class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        int maxHCount = 1, maxVCount = 0, tempH = 1, tempV = 1;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hLen = hBars.size();
        int vLen = vBars.size();
        for(int i =1; i< max(hLen, vLen); i++){
            if(i<hLen && hBars[i]- hBars[i-1] == 1){
                tempH++;
            }else if(i<hLen){
                maxHCount = max(maxHCount, tempH);
                tempH = 1;
            }
            if(i<vLen && vBars[i]- vBars[i-1] == 1){
                tempV++;
            }else if(i<vLen){
                maxVCount = max(maxVCount, tempV);
                tempV = 1;
            }
        }
        maxHCount = max(maxHCount, tempH);
        maxVCount = max(maxVCount, tempV);
    
        int len =  min(maxHCount, maxVCount)+1;
        return len*len;
    }
};