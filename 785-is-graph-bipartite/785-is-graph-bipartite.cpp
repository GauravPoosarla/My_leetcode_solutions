class Solution {
private:
    bool bipartiteDFS(int node, vector<vector<int>>& graph, vector<int>& color)
    {
        if(color[node] == -1)
            color[node] = 1;
        
        for(auto it: graph[node])
        {
            if(color[it] == -1)
            {
                color[it] = 1 - color[node];
                if(!bipartiteDFS(it, graph, color))
                    return false;
                else if(color[node] == color[it])
                    return false;
            }
        }
        return true;
    }
    bool bipartiteBFS(int src, vector<vector<int>>& graph, vector<int>& color)
    {
        queue<int> q;
        q.push(src);
        color[src] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto i: graph[node])
            {
                if(color[i] == -1)
                {
                    color[i] = 1 - color[node];
                    q.push(i);
                }
                else if(color[i] == color[node])
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i=0; i<graph.size(); i++)
        {
            if(color[i] == -1)
            {
                if(!bipartiteBFS(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};