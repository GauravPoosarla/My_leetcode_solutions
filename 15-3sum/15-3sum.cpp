class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            int targetToFind = 0 - nums[i];
            int start = i+1;
            int end = n-1;
            
            while(start < end)
            {
                int two_sum = nums[start] + nums[end];
                if(two_sum < targetToFind)
                {
                    start++;
                }
                else if(two_sum > targetToFind)
                {
                    end--;
                }
                else
                {
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[start]);
                    triplet.push_back(nums[end]);
                    sort(triplet.begin(), triplet.end());
                    res.push_back(triplet);
                    
                    while(start < end and nums[start] == triplet[1])
                        start++;
                    while(start < end and nums[end] == triplet[2])
                        end--;
                }
            }
            while(i+1 < n and nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};