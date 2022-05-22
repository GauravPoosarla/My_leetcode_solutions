class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++)
        {
            int target = 0 - nums[i];
            int start = i+1;
            int end = nums.size()-1;
            
            while(start < end)
            {
                if(nums[start] + nums[end] == target)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    sort(temp.begin(), temp.end());
                    result.push_back(temp);
                    
                    while(start < end and nums[start] == temp[1])
                        start++;
                    
                    while(start < end and nums[end] == temp[2])
                        end--;
                }
                else if(nums[start] + nums[end] < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
            
            while(i+1 < nums.size() and nums[i] == nums[i+1])
                i++;
        }
        return result;
    }
};