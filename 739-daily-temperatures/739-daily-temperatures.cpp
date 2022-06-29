class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> result(n, 0);
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() and st.top().first <= temperatures[i])
                st.pop();
            if(!st.empty())
                result[i] = st.top().second - i;
            
            st.push({temperatures[i], i});
        }
        return result;
    }
};