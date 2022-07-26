class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_var = INT_MIN;
        int i=0, j=height.size()-1;
        
        while(i<j)
        {
            int min_var = min(height[i], height[j]);
            min_var = min_var * (j-i);
            max_var = max(max_var, min_var);
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return max_var;
    }
};