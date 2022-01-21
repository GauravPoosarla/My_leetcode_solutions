class Solution {
public:
    int get_peak_index(vector<int> &A, int left, int right)
    {
        int mid = left + (right - left) / 2;

        if (left >= right)
            return left;

        if (A[mid] >= A[mid + 1])
        {
            return get_peak_index(A, left, mid);
        }
        else
        {
            return get_peak_index(A, mid+1, right);
        }

    }

    int peakIndexInMountainArray(vector<int> &A)
    {

        int ans = get_peak_index(A, 0, A.size() - 1);
        return ans;
    }
};