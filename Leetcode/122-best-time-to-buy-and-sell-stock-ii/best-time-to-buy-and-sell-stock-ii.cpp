class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int mx=0;
        int start=prices[0];
        for(int i=1;i<prices.size();i++){
            if(start<prices[i]){
                mx+=prices[i]-start;
            }
            start=prices[i];
        }
        return mx;
    }
};