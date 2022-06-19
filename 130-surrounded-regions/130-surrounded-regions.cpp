class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& board)
    {
        if(i < 0 or i >= board.size() or j < 0 or j >= board[0].size())
            return;
        if(board[i][j] != 'O')
            return;
        
        board[i][j] = 'Y';
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for(int k=0; k<4; k++)
        {
            dfs(i+dx[k], j+dy[k], board);
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 or board[0].size() == 0)
            return;
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i=0; i<cols; i++)
        {
            if(board[0][i] == 'O')
                dfs(0, i, board);
            if(board[rows-1][i] == 'O')
                dfs(rows-1, i, board);
        }
        
        for(int i=1; i<rows-1; i++)
        {
            if(board[i][0] == 'O')
                dfs(i, 0, board);
            if(board[i][cols-1] == 'O')
                dfs(i, cols-1, board);
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