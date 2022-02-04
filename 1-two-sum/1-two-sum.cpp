class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force:
        // TC: O(n^2)
        // SC: O(1)
        // vector<int> result;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     for(int j=i+1; j<nums.size(); j++)
        //     {
        //         if(nums[i] + nums[j] == target)
        //         {
        //             result.push_back(i);
        //             result.push_back(j);
        //         }
        //     }
        // }
        // return result;
        
        // Efficient Code:
        // TC: O(n)
        // SC: O(n)
        unordered_map<int,int> mp;
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(target-nums[i]) != mp.end())
            {
                result.push_back(i);
                result.push_back(mp[target-nums[i]]);
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return result;
    }
};