class Solution {
public:
    bool canReach(vector<int>& A, int cur) {
        if(cur < 0 || cur >= size(A) || A[cur] < 0) 
            return false;                 
        A[cur] *= -1;       // mark as visited by making -ve
        return A[cur] == 0 || canReach(A, cur + A[cur]) || canReach(A, cur - A[cur]);  
    }
};