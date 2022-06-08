class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        auto endPos = nums.begin() + k;
        pq = priority_queue<int, vector<int>, greater<int>> (nums.begin(), endPos);
        
        for(int i=k; i<nums.size(); i++)
        {
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();            
    }
};