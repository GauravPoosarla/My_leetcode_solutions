class Solution {
private:
    bool isCompatible(vector<int>& input, int distance, int balls)
    {
        int cntBalls = 1;
        int lastPlacedBasket = input[0];
        
        for(int i=1; i<input.size(); i++)
        {
            if(input[i] - lastPlacedBasket >= distance)
            {
                cntBalls++;
                lastPlacedBasket = input[i];
            }
        }
        if(cntBalls >= balls)
            return true;
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