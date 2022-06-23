class Solution {
private:
    bool isValid(int i, int j, int m, int n)
    {
        if(i < 0 or j < 0 or i == m or j == n)
            return false;
        return true;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                    result[i][j] = 0;
                }
            }
        }
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nx = node.first + dx[i];
                int ny = node.second + dy[i];
                
                if(isValid(nx, ny, m, n) and result[nx][ny] == -1)
                {
                    q.push({nx, ny});
                    result[nx][ny] = result[node.first][node.second]+1;
                }
            }
        }
        return result;
    }
};