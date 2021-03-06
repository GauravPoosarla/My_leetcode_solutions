class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if(arr[curr] == 0)
                return true;
            if(arr[curr] < 0)
                continue;
            if(curr + arr[curr] < arr.size())
                q.push(curr + arr[curr]);
            if(curr - arr[curr] >= 0)
                q.push(curr - arr[curr]);
            arr[curr] *= -1;
        }
        return false;
    }
};