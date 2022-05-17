class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> rotated(matrix.size(), vector<int> (matrix[0].size(), 0));
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                rotated[j][matrix.size()-i-1] = matrix[i][j];
            }
        }
        
        matrix = rotated;
        return ;
    }
};