class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // BruteForce 
        // TC: O(n)
        // SC: O(n)
        // unordered_map<int, int> mp;
        // int max = INT_MIN;
        // int ans = 0;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     mp[nums[i]]++;
        //     if(max < mp[nums[i]])
        //     {
        //         max = mp[nums[i]];
        //         ans = i;
        //     }
        // }
        // return nums[ans];
        
        // BruteForce with less space
        // TC: O(nlogn)
        // SC: O(1)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];
        
        //Optimised
        // TC: O(n)
        // SC: O(1)
        
        int candidate = 0;
        int votes = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(votes == 0)
            {
             candidate = nums[i];
            }
            if(candidate == nums[i])
            {
                votes++;
            }
            else
            {
                votes--;
            }
        }
        return candidate;
    }
};