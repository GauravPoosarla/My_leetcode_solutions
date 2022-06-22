class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int i, prev, n = a.size(), ans = 1, lastIndex = 0, ind = 1;
        sort(a.begin(), a.end());
        vector<int> dp(n, 1), hash(n);
        for(i = 0; i < n; i++) {
            hash[i] = i;
            for(prev = 0; prev < i; prev++) {
                if(a[i] % a[prev] == 0 && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(ans < dp[i]) {
                ans = dp[i];
                lastIndex = i;
            }
        }
        vector<int> lis(ans);
        lis[0] = a[lastIndex];
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            lis[ind++] = a[lastIndex];
        }
        reverse(lis.begin(), lis.end());
        return lis;
    }
};