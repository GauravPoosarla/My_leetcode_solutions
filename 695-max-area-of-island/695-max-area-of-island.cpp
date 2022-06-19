class Solution {
private:
    void bfs(int i, int j, int rows, int cols, vector<vector<int>>& grid, int& max_area)
    {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        queue<pair<int, int>> q;
        q.push({i, j});
        int curr_area = 1;
        
        while(!q.empty())
        {
            max_area = max(max_area, curr_area++);
            auto it = q.front();
            q.pop();
            
            int currx = it.first;
            int curry = it.second;
            grid[currx][curry] = 0;
            
            for(int i=0; i<4; i++)
            {
                int nx = currx + dx[i];
                int ny = curry + dy[i];
                
                if(nx >= 0 and ny >= 0 and nx < rows and ny < cols and grid[nx][ny] == 1)
                {
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int max_area = 0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    bfs(i, j, rows, cols, grid, max_area);
                }
            }
        }
        return max_area;
    }
};