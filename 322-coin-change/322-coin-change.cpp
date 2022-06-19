class Solution {
private:
    int coinChange(int index, vector<int>& coins, int amount, vector<vector<int>>& dp)
    {
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        if(index == 0)
        {
            if(amount % coins[index] == 0)
                return amount/coins[index];
            return 1e9;
        }
        int notPick = 0 + coinChange(index-1, coins, amount, dp);
        
        int pick = 1e9;
        if(coins[index] <= amount)
            pick = 1 + coinChange(index, coins, amount-coins[index], dp);
        return dp[index][amount] = min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        for(int amt = 0; amt <= amount; amt++)
        {
            dp[0][amt] = amt%coins[0] == 0 ? amt/coins[0] : 1e9;
        }
        
        for(int index = 1; index<n; index++)
        {
            for(int amt = 0; amt<=amount; amt++)
            {
                int notPick = 0 + dp[index-1][amt];
                int pick = 1e9;
                if(coins[index] <= amt)
                    pick = 1 + dp[index][amt-coins[index]];
                
                dp[index][amt] = min(pick, notPick);
            }
        }
        if(dp[n-1][amount] >= 1e9)
            return -1;
        else
            return dp[n-1][amount];
    }
};