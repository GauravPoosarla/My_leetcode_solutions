class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[triangle.size()-1].size();
        
        vector<int> nextRow(m, 0), currRow(m, 0);
        
        for(int i=0; i<m; i++)
        {
            nextRow[i] = triangle[m-1][i];
        }
        
        for(int i = m-2; i >= 0; i--)
        {
            for(int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + nextRow[j];
                int diag_down = triangle[i][j] + nextRow[j+1];
                
                currRow[j] = min(down, diag_down);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};