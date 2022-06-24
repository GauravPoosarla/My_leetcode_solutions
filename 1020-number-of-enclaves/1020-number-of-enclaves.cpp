class Solution {
private:
    bool isBoundary(int i, int j, int m, int n)
    {
        if(i == 0 or j == 0 or i == m-1 or j == n-1)
            return true;
        return false;
    }
    
    bool isValid(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        if(i >= 0 and j >= 0 and i <= m-1 and j <= n-1 and grid[i][j] == 1)
            return true;
        return false;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isBoundary(i, j, m, n) and grid[i][j] == 1)
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            int x = node.first;
            int y = node.second;
            
            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(isValid(nx, ny, m, n, grid))
                {
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans += grid[i][j];
            }
        }
        return ans;
    }
};