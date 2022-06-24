class Solution {
private:
    void dfs(int i, int j, int m, int n, int& res, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        if(i < 0 or j < 0 or i >= m or j >= n)
            return ;
        if(grid2[i][j] == 0)
            return;
        if(grid1[i][j] == 0 and grid2[i][j] == 1)
            res = 0;
        
        grid2[i][j] = 0;
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for(int k=0; k<4; k++)
        {
            dfs(i+dx[k], j+dy[k], m, n, res, grid1, grid2);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid2[i][j] == 1)
                {
                    int res = 1;
                    dfs(i, j, m, n, res, grid1, grid2);
                    ans += res;
                }
            }
        }
        return ans;
    }
};