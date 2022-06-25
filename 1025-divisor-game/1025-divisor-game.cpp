class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n+1, false);
        dp[0] = false;
        dp[1] = false;
        
        for(int x = 2; x <= n; x++)
        {
            if(dp[x-1] == false)
                dp[x] = true;
        }
        return dp[n];
    }
};