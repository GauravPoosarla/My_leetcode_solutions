class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0)); // n+2 because we have to handle for n-1 index.
        
        for(int index = n-1; index >= 0; index--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                int profit;
                if(buy == 0)
                {
                    profit = max(0 + dp[index+1][0], -prices[index] + dp[index+1][1]);
                }
                
                else if(buy == 1)
                {
                    profit = max(0 + dp[index+1][1], prices[index] + dp[index+2][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][0];
    }
};