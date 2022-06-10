class Solution {
private:
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