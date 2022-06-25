class Solution {
    bool f(int n, vector<int>& dp) {
        
        if(n <= 1)
            return false;
        
        if(dp[n] != -1)
            return dp[n];
        for(int x=1; x<n; x++)
        {
            if(n % x == 0)
            {
                if(f(n-x, dp) == false)
                    return dp[n] = true;
            }
        }
        return dp[n] = false;
    }
public:
    bool divisorGame(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};