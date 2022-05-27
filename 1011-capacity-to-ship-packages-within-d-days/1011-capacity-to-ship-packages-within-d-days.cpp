class Solution {
private:
    bool isValid(vector<int>& weights, int days, int totalCap)
    {
        int count = 1, sum = 0;
        for(int i=0; i<weights.size(); i++)
        {
            sum += weights[i];
            if(sum > totalCap)
            {
                count++;
                sum = weights[i];
            }
        }
        if(count <= days)
            return true;
        return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(isValid(weights, days, mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};