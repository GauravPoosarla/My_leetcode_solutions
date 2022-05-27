class Solution {
private:
    bool isValid(vector<int>& dist, double hour, int mid)
    {
        double time = 0.0;
        for(int i=0; i<dist.size()-1; i++)
        {
            time += ceil((double) dist[i]/mid);
        }
        time += (double)dist.back()/mid;
        if(time <= hour)
            return true;
        
        return false;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        
        int low = 1;
        int high = 1e7;
        
        int result = -1;
        while(low <= high)
        {
            int mid = (high + low)/2;
            if(isValid(dist, hour, mid))
            {
                result = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return result;
    }
};