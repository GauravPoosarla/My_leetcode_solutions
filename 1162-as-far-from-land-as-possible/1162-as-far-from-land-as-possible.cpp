class Solution {
private:
    bool isValid(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        if(i < 0 or j < 0 or i >= m or j >= n or grid[i][j] == 1)
            return false;
        return true;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0;j <n; j++)
            {
                if(grid[i][j] == 1)
                    q.push({i, j});
            }
        }
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int count = 0;
        while(!q.empty())
        {
            int size = q.size();
            count++;
            
            for(int i=0; i<size; i++)
            {
                auto node = q.front();
                q.pop();
                
                int x = node.first;
                int y = node.second;
                
                for(int i=0; i<4; i++)
                {
                    int nx = x + dx[i];
                    int ny =y + dy[i];
                    
                    if(isValid(nx, ny, m, n, grid))
                    {
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
        }
        return count > 1 ? count-1 : -1;
    }
};