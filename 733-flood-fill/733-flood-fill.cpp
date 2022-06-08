class Solution {
private:
    void solve(vector<vector<int>>& image, int sr, int sc, int newColor, int rows, int cols, int source)
    {
        if(sr < 0 or sr >= rows or sc < 0 or sc >= cols)
            return ;
        else if(image[sr][sc] != source)
            return;
        
        image[sr][sc] = newColor;
        
        solve(image, sr-1, sc, newColor, rows, cols, source); // Top
        solve(image, sr+1, sc, newColor, rows, cols, source); // Down
        solve(image, sr, sc-1, newColor, rows, cols, source); // Left
        solve(image, sr, sc+1, newColor, rows, cols, source); // Right
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc])
            return image;
        int rows = image.size();
        int cols = image[0].size();
        int source = image[sr][sc];
        solve(image, sr, sc, newColor, rows, cols, source);
        return image;
    }
};