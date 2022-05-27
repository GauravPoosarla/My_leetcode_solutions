class Solution {
private:
    bool isValid(vector<int>& piles, int h, int mid)
    {
        int countHours = 0;
        for(int i=0; i<piles.size(); i++)
        {
            countHours += ceil(1.0 * piles[i] / mid);
        }
        if(countHours <= h)
            return true;
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(isValid(piles, h, mid))
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