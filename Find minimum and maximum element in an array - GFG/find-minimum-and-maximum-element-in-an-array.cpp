// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends

#include<bits/stdc++.h>
pair<long long, long long> getMinMax(long long a[], int n) 
{
    long long mini = INT_MAX;
    long long maxi = INT_MIN;
    pair<long long, long long> ans;
    
    for(int i=0; i<n; i++)
    {
        if(mini > a[i])
        {
            mini = a[i];
        }
        if(maxi < a[i])
        {
            maxi = a[i];
        }
    }
    ans.first = mini;
    ans.second = maxi;
    return ans;
}