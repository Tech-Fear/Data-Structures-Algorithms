class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int firstBuy = INT_MIN, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;

        for (int price : prices) {
            firstBuy = max(firstBuy, -price);
            firstSell = max(firstSell, price + firstBuy);
            secondBuy = max(secondBuy, firstSell - price);
            secondSell = max(secondSell, price + secondBuy);
        }

        return secondSell;
    }
};