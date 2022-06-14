class Solution {
private:
    int uniquePaths(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if(i >= 0 and j >= 0 and obstacleGrid[i][j] == 1)
            return 0;
        if(i == 0 and j == 0)
            return 1;
        if(i < 0 or j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = uniquePaths(i-1, j, m, n, obstacleGrid, dp);
        int left = uniquePaths(i, j-1, m, n, obstacleGrid, dp);
        
        return dp[i][j] = up + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePaths(m-1, n-1, m, n, obstacleGrid, dp);
    }
};