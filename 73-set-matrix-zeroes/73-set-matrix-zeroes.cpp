class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int>dummy1(matrix.size(), -1);
        vector<int>dummy2(matrix[0].size(), -1);
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    dummy1[i] = 0;
                    dummy2[j] = 0;
                    
                }
            }
        }
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(dummy1[i] == 0 || dummy2[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        return ;
    }
};