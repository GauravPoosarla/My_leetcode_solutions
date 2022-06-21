class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 and n == 1)
            return 1;
        vector<int> inDegrees(n+1, 0), outDegrees(n+1, 0);
        for(auto edge : trust)
        {
            outDegrees[edge[0]]++;
            inDegrees[edge[1]]++;
        }
        
        for(int i=0; i<=n; i++)
        {
            if(outDegrees[i] == 0 and inDegrees[i] == n-1)
                return i;
        }
        return -1;
    }
};