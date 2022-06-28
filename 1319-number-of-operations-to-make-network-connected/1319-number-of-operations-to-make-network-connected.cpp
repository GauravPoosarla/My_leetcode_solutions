class Solution {
private:
    void dfs(vector<int> adj[], vector<bool>& visited, int node)
    {
        visited[node] = true;
        for(auto it : adj[node])
        {
            if(!visited[it])
                dfs(adj, visited, it);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;
        vector<int> adj[n];
        for(auto v: connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(adj, visited, i);
                components++;
            }
        }
        return components-1;
    }
};