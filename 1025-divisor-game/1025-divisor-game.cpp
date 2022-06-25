class Solution {
    bool f(int index, vector<int>& dp) {
        
        if(index <= 1)
            return false;
        
        if(dp[index] != -1)
            return dp[index];
        
        for(int x=1; x<index; x++)
        {
            if(index % x == 0)
            {
                if(f(index-x, dp) == false)
                    return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
public:
    bool divisorGame(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};