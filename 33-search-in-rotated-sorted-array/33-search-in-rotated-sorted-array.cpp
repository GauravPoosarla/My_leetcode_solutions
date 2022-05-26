class Solution {
public:
    int search(vector<int>& a, int target) {
        int low = 0, high = a.size()-1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(a[mid] == target)
                return mid;
            
            // left side is sorted
            if(a[low] <= a[mid])
            {
                if(target >= a[low] and target <= a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(target >= a[mid] and target <= a[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};