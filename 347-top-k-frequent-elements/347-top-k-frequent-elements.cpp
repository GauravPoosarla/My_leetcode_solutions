class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        vector<int> result;
        priority_queue<pair<int,int>> pq; //first represents the index and second represents the value
        
        for(auto m: mp)
        {
            pq.push({m.second, m.first});
            if(pq.size() > mp.size() - k)
            {
                result.push_back(pq.top().second);
                pq.pop();
            }
        }
        return result;
    }
};