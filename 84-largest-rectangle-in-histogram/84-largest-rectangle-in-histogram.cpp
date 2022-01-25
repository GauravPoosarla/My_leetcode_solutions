// class Solution {
// public:
//     int largestRectangleArea(vector<int>& arr) {
//         int res = 0;
//         for(int i=0; i<heights.size(); i++)
//         {
//             int curr = heights[i];
//             for(int j=i-1; j>=0; j--)
//             {
//                 if(heights[j] >= heights[i])
//                 {
//                     curr+=heights[i];
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             for(int j=i+1; j<heights.size(); j++)
//             {
//                 if(heights[j] >= heights[i])
//                 {
//                     curr+=heights[i];
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             res = max(res, curr);
//         }
//         return res;
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n = height.size(), area = 0;
        stack<int> indexes;
        for (int i = 0; i < n; i++) {
            while (!indexes.empty() && height[indexes.top()] > height[i]) {
                int h = height[indexes.top()]; indexes.pop();
                int l = indexes.empty() ? -1 : indexes.top();
                area = max(area, h * (i - l - 1));
            }
            indexes.push(i);
        }
        return area; 
    }
};
        
