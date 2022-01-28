// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m)
    {
        if ((x>=0 and x<n) and (y>=0 and y<n) and visited[x][y] == 0 and m[x][y] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void findPath(vector<vector<int>> &m, int n, vector<string> &result, int x, int y, vector<vector<int>> visited, string path)
    {
        //base case
        if(x == n-1 and y == n-1)
        {
            result.push_back(path);
            return;
        }
        visited[x][y] = 1;
        
        //possible movements
        
        //down
        int newx = x+1;
        int newy = y;
        if(isSafe(newx, newy, n, visited, m))
        {
            path.push_back('D');
            findPath(m, n, result, newx, newy, visited, path);
            path.pop_back();
        }
        
        //left
        newx = x;
        newy = y-1;
        if(isSafe(newx, newy, n, visited, m))
        {
            path.push_back('L');
            findPath(m, n, result, newx, newy, visited, path);
            path.pop_back();
        }
        
        //right
        newx = x;
        newy = y+1;
        if(isSafe(newx, newy, n, visited, m))
        {
            path.push_back('R');
            findPath(m, n, result, newx, newy, visited, path);
            path.pop_back();
        }
        
        //up
        newx = x-1;
        newy = y;
        if(isSafe(newx, newy, n, visited, m))
        {
            path.push_back('U');
            findPath(m, n, result, newx, newy, visited, path);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> result;
        if(m[0][0] == 0)
        {
            return result;
        }
        int srcx = 0;
        int srcy = 0;
        
        vector<vector<int>> visited = m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                visited[i][j] = 0;
            }
        }
        string path = "";
        findPath(m, n, result, srcx, srcy, visited, path);
        sort(result.begin(), result.end());
        return result;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends