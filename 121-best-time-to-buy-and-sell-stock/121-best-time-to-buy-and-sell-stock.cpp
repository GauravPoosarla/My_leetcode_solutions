class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            if(minPrice > prices[i])
                minPrice = prices[i];
            int profit = prices[i] - minPrice;
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
};