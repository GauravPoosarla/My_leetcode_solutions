class Solution {
private:
    int uniquePath(int i, int j, int m, int n, vector<vector<int>>& dp)
    {
        if(i == 0 and j == 0)
            return 1;
        if(i < 0 or j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = uniquePath(i, j-1, m, n, dp);
        int right = uniquePath(i-1, j, m, n, dp);
        
        return dp[i][j] = left + right;
    }
        
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePath(m-1, n-1, m, n, dp);
    }
};