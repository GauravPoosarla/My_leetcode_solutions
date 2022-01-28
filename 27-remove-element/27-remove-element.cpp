class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while(i < n)
        {
            if(nums[i] == val)
            {
                int j = i+1;
                while(j < n)        
                {
                    nums[j-1] = nums[j];
                    j++;
                }
                n--;                
            }
            if(nums[i]!=val)        
                i++;
        }
        return n;                   
    }
};