class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minPrice = INT_MAX;
        
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            int profit = prices[i] - minPrice;
            if(maxProfit < profit)
            {
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};