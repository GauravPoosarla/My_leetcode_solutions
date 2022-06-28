class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> curr(n, 0), prev(n, 0);
        
        for(int j=0; j<m; j++)
        {
            prev[j] = matrix[0][j];
        }
        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int up = matrix[i][j] + prev[j];
                
                int up_left = matrix[i][j];
                if(j > 0)
                    up_left += prev[j-1];
                else
                    up_left += 1e9;
                
                int up_right = matrix[i][j];
                if(j+1 < n)
                    up_right += prev[j+1];
                else
                    up_right += 1e9;
                
                curr[j] = min({up, up_left, up_right});
            }
            prev = curr;
        }
        
        int mini = INT_MAX;
        for(int i=0; i<n; i++)
        {
            mini = min(mini, prev[i]);
        }
        return mini;
    }
};