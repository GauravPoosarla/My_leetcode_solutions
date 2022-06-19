class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        for(int j = 0; j<cols; j++)
        {
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];
                
                int up_left = matrix[i][j];
                if(j>0)
                    up_left += dp[i-1][j-1];
                else
                    up_left += 1e9;
                
                int up_right = matrix[i][j];
                if(j+1 < cols)
                    up_right += dp[i-1][j+1];
                else
                    up_right += 1e9;
                
                dp[i][j] = min({up, up_left, up_right});
            }
        }
        int mini = INT_MAX;
        for(int i=0; i<cols; i++)
        {
            mini = min(mini, dp[rows-1][i]);
        }
        return mini;
    }
};