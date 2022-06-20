class Solution {
private:
    bool isValid(int x, int y, vector<vector<int>>& image, int color)
    {
        if(x >= 0 and y >= 0 and x < image.size() and y < image[0].size() and image[x][y] == color)
            return true;
        return false;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(sr==sc && image[sr][sc]==color) 
            return image;
        
        int m = image.size();
        int n = image[0].size();
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int sourceCol = image[sr][sc];
        
        image[sr][sc] = color;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            
            for(int i=0; i<4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(isValid(nx, ny, image, sourceCol))
                {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};