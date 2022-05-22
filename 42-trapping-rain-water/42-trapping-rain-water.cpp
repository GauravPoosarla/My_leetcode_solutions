class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefix[n];
        int suffix[n];
        
        prefix[0] = height[0];
        for(int i=1; i<n; i++)
        {
            int val = max(prefix[i-1], height[i]);
            prefix[i] = val;
        }
        
        suffix[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--)
        {
            int val = max(suffix[i+1], height[i]);
            suffix[i] = val;
        }
        
        int waterTrapped = 0;
        for(int i=0; i<n; i++)
        {
            waterTrapped += min(prefix[i], suffix[i]) - height[i];
        }
        return waterTrapped;
    }
};