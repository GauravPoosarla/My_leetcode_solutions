class Solution {
private:
    bool isBoundary(int i, int j, int m, int n)
    {
        if(i == 0 or j == 0 or i == m-1 or j == n-1)
            return true;
        return false;
    }
    
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        if(i < 0 or j < 0 or i >= m or j >= n or grid[i][j] == 0)
            return 0;
        
        grid[i][j] = 0;
        return 1 + dfs(i+1, j, m, n, grid) + dfs(i, j+1, m, n, grid) + dfs(i-1, j, m, n, grid) + dfs(i, j-1, m, n, grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int all_ones = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    all_ones++;
            }
        }
        
        int closed_ones = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isBoundary(i, j, m, n) and grid[i][j] == 1)
                    closed_ones += dfs(i, j, m, n, grid);
            }
        }
        return all_ones - closed_ones;
    }
};