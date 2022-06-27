class Solution {
private:
    int f(int i, int j, int m, int n, vector<vector<int>>& dp)
    {
        if(i == 0 and j == 0)
            return 1;
        if(i < 0 or j < 0 or i >=m or j >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = f(i-1, j, m, n, dp);
        int left = f(i, j-1, m, n, dp);
        
        return dp[i][j] = up + left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, m, n, dp);
    }
};