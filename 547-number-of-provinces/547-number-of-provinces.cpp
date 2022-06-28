class Solution {
private:
    void dfs(int i, vector<int>& visited, vector<vector<int>>& isConnected)
    {
        visited[i] = 1;
        for(int j=0;j<isConnected.size();j++)
        {
            if(isConnected[i][j] == 1 and !visited[j])
                dfs(j, visited, isConnected);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int provinces = 0;
        for(int i=0; i<isConnected.size(); i++)
        {
            if(!visited[i])
            {
                provinces++;
                dfs(i, visited, isConnected);
            }
        }
        return provinces;
    }
};