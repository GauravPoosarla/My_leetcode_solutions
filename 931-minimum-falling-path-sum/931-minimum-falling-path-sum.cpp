class Solution {
    int minFallingPathSum(int i, int j, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(j < 0 or j >= n)
            return 1e8;
        
        if(i == 0)
            return matrix[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = matrix[i][j] + minFallingPathSum(i-1, j, m, n, matrix, dp);
        int up_left = matrix[i][j] + minFallingPathSum(i-1, j-1, m, n, matrix, dp);
        int up_right = matrix[i][j] + minFallingPathSum(i-1, j+1, m, n, matrix, dp);
        
        return dp[i][j] = min({up, up_left, up_right});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int mini = INT_MAX;
        for(int j=0; j<n; j++)
        {
            int ans = minFallingPathSum(m-1, j, m, n, matrix, dp);
            mini = min(mini, ans);
        }
        return mini;
    }
};