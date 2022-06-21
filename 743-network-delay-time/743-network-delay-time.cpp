class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N+1, INT_MAX);
        dist[K] = 0;
        for(int i=0; i<N; i++)
        {
            for(auto e: times)
            {
                int u = e[0], v = e[1], w = e[2];
                if(dist[u] != INT_MAX and dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
        }
        
        int maxi = INT_MIN;
        for(int i=1; i<=N; i++)
        {
            maxi = max(maxi, dist[i]);
        }
        return maxi == INT_MAX ? -1 : maxi;
    }
};