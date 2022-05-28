class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        // indgree contains {indegree, node} of every node from 0 to n-1.
        vector<pair<int, int>> indegree;
        for (int i=0; i<n; i++) indegree.push_back({0, i});
        for (auto rd : roads) {
            indegree[rd[0]].first++;
            indegree[rd[1]].first++;
        }
                
        sort(begin(indegree), end(indegree), greater<pair<int, int>>());
        
        int impt(n);
        // importance contains importance assigned to all the nodes.
        vector<int> importance(n, 0);
        for (auto& b : indegree)  importance[b.second] = impt--;
        
        long long ans(0);
        for (auto& road : roads)
            ans += (importance[road[0]] + importance[road[1]]);
        
        return ans;
    }
};