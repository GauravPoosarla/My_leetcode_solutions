class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.empty())
            return result;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int targetFinal = target - nums[i] - nums[j];
                int start = j+1;
                int end = n-1;
                
                while(start < end)
                {
                    int two_sum = nums[start] + nums[end];
                    if(two_sum < targetFinal)
                        start++;
                    else if(two_sum > targetFinal)
                        end--;
                    else
                    {
                        vector<int> quadruple;
                        quadruple.push_back(nums[i]);
                        quadruple.push_back(nums[j]);
                        quadruple.push_back(nums[start]);
                        quadruple.push_back(nums[end]);
                        result.push_back(quadruple);
                        
                        // processing the duplicates for number 3
                        while(start < end and nums[start] == quadruple[2])
                            start++;
                        
                        // processing the duplicates for number 4
                        while(start < end and nums[end] == quadruple[3])
                            end--;
                    }
                }
                // processing the duplicates for number 2
                while(j+1 < n and nums[j] == nums[j+1])
                    j++;
            }
            // processing the duplicates for number 1
            while(i+1 < n and nums[i] == nums[i+1])
                i++;
        }
        return result;
    }
};