class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int k, i;
        for(k=nums.size()-2; k>=0; k--)
        {
            if(nums[k] < nums[k+1])
            {
                break;
            }
        }
        
        if(k < 0)
        {
            // largest permutation
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for(i=nums.size()-1; i>k; i--)
            {
                if(nums[k] < nums[i])
                {
                    break;
                }
            }
        swap(nums[k], nums[i]);
        reverse(nums.begin()+k+1, nums.end());
        }
    }
};