class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        if(!matrix.size()) return false;
        int end = (matrix.size() * matrix[0].size()) - 1;
        
        while(start <= end)
        {
            int mid = (start + end)/2;
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] == target)
            {
                return true;
            }
            else if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] > target)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return false;
    }
};