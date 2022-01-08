class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int index;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        int lsum =0;
        int rsum = sum-nums[0];
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0)
            {
                lsum += nums[i-1];
                rsum -= nums[i];
            }
            
            if(lsum == rsum)
            {
                return i;
            }
        }
        return -1;
    }
};