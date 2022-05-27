class Solution {
private:
    bool isValid(vector<int>& bloomDay, int m, int k, int mid) 
    {
        int adjacent = 0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i] <= mid)
                adjacent += 1;
            else
                adjacent = 0;
            
            if(adjacent == k)
            {
                adjacent = 0;
                m--;
            }
        }
        return m <= 0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size())
            return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(low <= high)  
        {
            int mid = (low+high)/2;
            if(isValid(bloomDay, m, k, mid))
            {
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return low;
    }
};