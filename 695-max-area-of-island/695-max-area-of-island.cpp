class Solution {
private:
    bool isValid(int i, int j, int rows, int cols, vector<vector<int>>& grid)
    {
        if(i >= 0 and i < rows and j >= 0 and j < cols and grid[i][j]==1)
            return true;
        return false;
    }
    
    int markAdjacentLands(int i, int j, int rows, int cols, vector<vector<int>>& grid)
    {
        if(isValid(i, j, rows, cols, grid))
        {
            grid[i][j] = 0;
        return 1 + markAdjacentLands(i+1, j, rows, cols, grid) + markAdjacentLands(i, j+1, rows, cols, grid) + markAdjacentLands(i-1, j, rows, cols, grid) + markAdjacentLands(i, j-1, rows, cols, grid);
        }
        
        return 0;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int maxArea = 0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = markAdjacentLands(i, j, rows, cols, grid);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};