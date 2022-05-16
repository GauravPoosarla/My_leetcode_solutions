class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k=0; k<rows; k++)
                    {
                        if(k == i)
                            continue;
                        if(matrix[k][j] != 0)
                            matrix[k][j] = -6969;
                    }
                    for(int k=0; k<cols; k++)
                    {
                        if(k == j)
                            continue;
                        if(matrix[i][k] != 0)
                            matrix[i][k] = -6969;
                    }
                }
            }
        }
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(matrix[i][j] == -6969)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        return ;
    }
};