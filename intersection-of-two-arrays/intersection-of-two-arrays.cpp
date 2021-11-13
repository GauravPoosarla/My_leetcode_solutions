class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        unordered_set<int> us;
        for(int i = 0; i < arr1.size(); i++)
          us.insert(arr1[i]);

        int res = 0;  
        for(int i = 0; i < arr2.size(); i++)
        {
            if(us.find(arr2[i]) != us.end())
            {
                res++;
                result.push_back(arr2[i]);
                us.erase(arr2[i]);
            }
        }
        return result;
    }
};