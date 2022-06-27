class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> prev(n);
        for(int i=0; i<m; i++)
        {
            vector<int> curr(n);
            for(int j=0; j<n; j++)
            {
                if(i == 0 and j == 0)
                {
                    curr[j] = grid[i][j];
                    continue;
                }
                
                int up = 0;
                if(i > 0)
                    up = grid[i][j] + prev[j];
                else
                    up = 1e9;
                
                int left = 0;
                if(j > 0)
                    left = grid[i][j] + curr[j-1];
                else
                    left = 1e9;
                
                curr[j] = min(up, left);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};