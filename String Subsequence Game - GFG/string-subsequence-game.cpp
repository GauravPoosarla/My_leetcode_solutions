// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> V; // vowels
    string T; // current string
    void recur(string& S, int idx, set<string>& R) {
        if (T.size() && V[T[0]] && !V[T.back()])
            R.insert(T);
        for (int i = idx; i < S.size(); i++) {
            T.push_back(S[i]);
            recur(S, i + 1, R);
            T.pop_back();
        }
    }
    set<string> allPossibleSubsequences(string S) {
        V.resize(128);
        V['a'] = V['e'] = V['i'] =
        V['o'] = V['u'] = 1;
        set<string> R;
        recur(S, 0, R);
        return R;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
  // } Driver Code Ends