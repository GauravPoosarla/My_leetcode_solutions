class Solution {
private:
    bool isValid(int i, int j, int rows, int cols)
    {
        if(i < 0 or i >= rows or j < 0 or j >= cols)
            return false;
        return true;
    }
    void bfs(int i, int j, vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        board[i][j] = 'Y';
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        queue<pair<int,int>> q;
        q.push({i, j});
        while(!q.empty())
        {
            int currx = q.front().first;
            int curry = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nx = currx + dx[i];
                int ny = curry + dy[i];
                if(!isValid(nx, ny, m, n))
                    continue;
                if(board[nx][ny] == 'O')
                {
                    q.push({nx, ny});
                    board[nx][ny] = 'Y';
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        if(rows == 0 or cols == 0)
            return;
        
        for(int i=0; i<cols; i++)
        {
            if(board[0][i] == 'O')
                bfs(0, i, board);
            if(board[rows-1][i] == 'O')
                bfs(rows-1, i, board);
        }
        
        for(int i=0; i<rows; i++)
        {
            if(board[i][0] == 'O')
                bfs(i, 0, board);
            if(board[i][cols-1] == 'O')
                bfs(i, cols-1, board);
        }
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(board[i][j] == 'Y')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};