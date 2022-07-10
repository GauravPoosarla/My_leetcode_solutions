class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-1;
        while(right - left >= k)
        {
            if(x - arr[left] <= arr[right] - x)
                right--;
            else
                left++;
        }
        
        vector<int> result;
        for(int i=left; i<=right; i++)
        {
            result.push_back(arr[i]);
        }
        return result;
    }
};