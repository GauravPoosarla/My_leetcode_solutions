class Solution {
private:
    bool isValid(int n, vector<int>& quantities, int mid)
    {
        int sum = 0;
        for(int i=0; i<quantities.size(); i++)
        {
            sum += (quantities[i] + mid - 1)/mid;
        }
        if(sum <= n)
            return true;
        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(isValid(n, quantities, mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};