class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int)matrix.size();
        if(n == 0)return false;
        
        int m = (int)matrix[0].size();
        if(m == 0)return false;
        
        int lo = 0, hi = n-1;
        int mid; // stores the row.
        while(lo<=hi){
            mid = lo + (hi - lo)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target)break;
            else if(matrix[mid][0]>target)hi = mid-1;
            else if(matrix[mid][m-1]<target)lo = mid+1;
        }
        // okay we have found the row.
        // now find the column?
        int col = 9;
        bool ans = false;
        for(int i = 0; i<m; i++){
            if(matrix[mid][i] == target){
                ans = true;
            }
        }
        return ans;
    }
};