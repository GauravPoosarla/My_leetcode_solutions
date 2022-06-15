class Solution {
private:
    int minimumTotal(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i == m-1)
            return triangle[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = triangle[i][j] + minimumTotal(i+1, j, m, triangle, dp);
        int down_left = triangle[i][j] + minimumTotal(i+1, j+1, m, triangle, dp);
        
        return dp[i][j] = min(down, down_left);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size(), -1));
        return minimumTotal(0, 0, triangle.size(), triangle, dp);
    }
};