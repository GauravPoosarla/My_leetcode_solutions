class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int max_end_here = 0;
        int start = 0;
        int end = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            max_end_here += nums[i];
            if(max_end_here > max_so_far)
            {
                max_so_far = max_end_here;
                end = i;
            }
            if(max_end_here < 0)
            {
                max_end_here = 0;
                start = i+1;
            }
        }
        // cout << start << " " << end << endl;
        return max_so_far;
    }
};