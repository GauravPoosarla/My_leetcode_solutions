class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = grid[0][0];
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == 0 and j == 0)
                    continue;
                
                int up = 0;
                if(i > 0)
                    up = grid[i][j] + dp[i-1][j];
                else
                    up = 1e9;
                
                int left = 0;
                if(j > 0)
                    left = grid[i][j] + dp[i][j-1];
                else
                    left = 1e9;
                
                dp[i][j] = min(up, left);
            }
        }
        return dp[m-1][n-1];
    }
};