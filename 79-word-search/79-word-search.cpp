class Solution {
private:
    bool dfs(int i, int j, int m, int n, int index, vector<vector<char>>& board, string word)
    {
        if(index == word.size())
            return true;
        
        if(i < 0 or j < 0 or i >= m or j >= n or board[i][j] != word[index])
            return false;
        
        board[i][j] = '0';
        bool ans = dfs(i+1, j, m, n, index+1, board, word) or
                   dfs(i, j+1, m, n, index+1, board, word) or 
                   dfs(i-1, j, m, n, index+1, board, word) or
                   dfs(i, j-1, m, n, index+1, board, word);
        board[i][j] = word[index];
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "")
            return false;
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == word[0] and dfs(i, j, m, n, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};