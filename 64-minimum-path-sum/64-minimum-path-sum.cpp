class Solution {
private:
    int f(int m, int n, int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i == 0 and j == 0)
            return grid[i][j];
        if(i < 0 or j < 0 or i >= m or j >= n)
            return INT_MAX;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = 0;
        if(j > 0)
            left = grid[i][j] + f(m, n, i, j-1, grid, dp);
        else
            left = 1e9;
        
        int up = 0;
        if(i > 0)
            up = grid[i][j] + f(m, n, i-1, j, grid, dp);
        else
            up = 1e9;
        
        return dp[i][j] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m, n, m-1, n-1, grid, dp);
    }
};