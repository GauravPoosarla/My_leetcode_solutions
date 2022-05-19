class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sz;
        for(auto num : nums)
        {
            sz.insert(num);
        }
        int longestConsec = 0;
        
        for(auto num : nums)
        {
            if(sz.count(num-1) == 0)
            {
                int currentNum = num;
                int currentConsec = 1;
                
                while(sz.count(currentNum + 1))
                {
                    currentConsec++;
                    currentNum++;
                }
                
                longestConsec = max(longestConsec, currentConsec);
            }
        }
        return longestConsec;
    }
};