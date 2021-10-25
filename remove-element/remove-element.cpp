class Solution {
public:
    int removeElement(vector<int>& A, int val) {
        int count = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] == val) 
                count++;
            else 
                A[i-count] = A[i];
        }
        return A.size()-count;
    }
};