class Solution {
private:
    int change(int index, int amount, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        if(index == 0)
            return amount%coins[index] == 0;
        if(amount == 0)
            return 1;
        int notPick = change(index-1, amount, coins, dp);
        int pick = 0;
        if(coins[index] <= amount)
            pick = change(index, amount-coins[index], coins, dp);
        
        return dp[index][amount] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return change(n-1, amount, coins, dp);
    }
};