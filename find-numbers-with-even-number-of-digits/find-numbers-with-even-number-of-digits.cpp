class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int total_count = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            int count = 1;
            while(nums[i] > 9)
            {
                nums[i] /= 10;
                count++;
            }
            if(count%2 == 0)
            {
                total_count++;
            }
        }
        return total_count;
    }
};