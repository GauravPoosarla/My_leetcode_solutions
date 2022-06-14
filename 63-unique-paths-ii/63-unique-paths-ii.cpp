class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = 1;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {   
                if((obstacleGrid[i][j] == 1) or (i == 0 and j == 0 ))
                {
                    continue;
                }
                else
                {
                    int left, up;
                    left = j > 0 ? dp[i][j-1] : 0;
                    up = i > 0 ? dp[i-1][j] : 0;
                    
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};