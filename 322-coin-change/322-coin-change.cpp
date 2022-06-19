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
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = coinChange(n-1, coins, amount, dp);
        if(ans == 1e9)
            return -1;
        return ans;
    }
};