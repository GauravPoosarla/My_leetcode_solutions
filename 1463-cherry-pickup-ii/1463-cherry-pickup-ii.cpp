class Solution {
private:
    int cherryPickup(int i1, int j1, int j2, int rows, int cols, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
    {
        if(j1 < 0 or j1 >= cols or j2 < 0 or j2 >= cols) // out of bound condition
            return -1e8;
        
        if(dp[i1][j1][j2] != -1)
            return dp[i1][j1][j2];
        
        if(i1 == rows-1) // reached destination
        {
            if(j1 == j2) // both robots are on the same cell. So, we have to consider only once.
                return grid[i1][j1];
            else
                return grid[i1][j1] + grid[i1][j2]; // both are on different cells. So, we can collect on both.
        }
        
        // possible actions:- 3*3 actions possible because we are moving both the robots simultaneously.
        
        
        int maxi = -1e8; // maintaining a maximum variable
        
        for(int dj1 = -1; dj1 <= +1; dj1++) // possible directions are {-1, 0, +1}
        {
            for(int dj2 = -1; dj2 <= +1; dj2++) // possible directions are {-1, 0, +1}
            {
                int value = 0;
                if(j1 == j2) // if both of them reach the same cell
                    value = grid[i1][j1];
                else
                    value = grid[i1][j1] + grid[i1][j2];
                
                value += cherryPickup(i1+1, j1+dj1, j2+dj2, rows, cols, grid, dp); // calling the recursive function 
                maxi = max(maxi, value); // updating the maximum value
            }
        }
        return dp[i1][j1][j2] = maxi; // storing the maximum value and returning
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int i1 = 0, j1 = 0; // represents robot-1
        int i2 = 0, j2 = grid[0].size() - 1; // represents robot-2
        
        int m = grid.size(); // total number of rows
        int n = grid[0].size(); // total number of columns
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return cherryPickup(i1, j1, j2, m, n, grid, dp); // helper recursive function
    }
};