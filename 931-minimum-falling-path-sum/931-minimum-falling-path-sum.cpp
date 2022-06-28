class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<n; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        
        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];
                
                int up_left = matrix[i][j];
                if(j > 0)
                    up_left += dp[i-1][j-1];
                else
                    up_left += 1e9;
                
                int up_right = matrix[i][j];
                if(j+1 < n)
                    up_right += dp[i-1][j+1];
                else
                    up_right += 1e9;
                
                dp[i][j] = min({up, up_left, up_right});
            }
        }
        
        int mini = INT_MAX;
        for(int i=0; i<n; i++)
        {
            mini = min(mini, dp[m-1][i]);
        }
        return mini;
    }
};