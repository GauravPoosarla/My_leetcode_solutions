class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Bruteforce
        // TC: O(N^2)
        // SC: O(1)
        // int count=0;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     int sum = nums[i];
        //     if(sum == k)
        //     {
        //         count++;
        //     }
        //     for(int j=i+1; j<nums.size(); j++)
        //     {
        //         cout << i << " " << j << endl;
        //         sum += nums[j];
        //         if(sum == k)
        //         {
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mp;
        
        vector<int> prefix(n);
        prefix[0] = nums[0];
        
        for(int i=1; i<n; i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        for(int i=0; i<n; i++)
        {
            if(prefix[i] == k)
            {
                count++;
            }
            
            if(mp.find(prefix[i] - k) != mp.end())
            {
                count += mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
        }
        return count;
    }
};