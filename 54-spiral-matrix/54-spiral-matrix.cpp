class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> result;
        int left = 0;
        int top = 0;
        int right = n-1;
        int down = m-1;
        
        int count = 0;
        while(count < m * n)
        {
            for(int i=top; i<=right; i++)
            {
                result.push_back(matrix[left][i]);
                count++;
            }
            left++;
            
            for(int i=left; i<=down; i++)
            {
                result.push_back(matrix[i][right]);
                count++;
            }
            right--;
            
            if(left > down)
                break;
            for(int i=right; i>=top; i--)
            {
                result.push_back(matrix[down][i]);
                count++;
            }
            down--;
            
            if(top > right)
                break;
            for(int i=down; i>=left; i--)
            {
                result.push_back(matrix[i][top]);
                count++;
            }
            top++;
        }
        return result;
    }
};