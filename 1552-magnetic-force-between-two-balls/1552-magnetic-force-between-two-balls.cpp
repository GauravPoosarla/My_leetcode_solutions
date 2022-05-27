class Solution {
private:
    bool isCompatible(vector<int>& input, int distance, int balls)
    {
        int n = input.size();
        int k = input[0];
        balls--;
        
        for(int i=1; i<n; i++)
        {
            if(input[i]-k >= distance)
            {
                balls--;
                if(balls == 0)
                    return true;
                
                k = input[i];
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) 
    {
        sort(position.begin(), position.end());
        int low = 0;
        int high = position[position.size()-1] - position[0];
        
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(isCompatible(position, mid, m))
            {
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
      return ans;
    }
};