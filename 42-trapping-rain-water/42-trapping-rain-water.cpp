class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int res = 0;
        int maxLeft = INT_MIN, maxRight = INT_MIN;
        
        while(left <= right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] > maxLeft)
                    maxLeft = height[left];
                else
                    res += maxLeft-height[left];
                
                left++;
            }
            else
            {
                if(height[right] >= maxRight)
                    maxRight = max(maxRight, height[right]);
                else
                    res += maxRight - height[right];
                
                right--;
            }
        }
        return res;
    }
};