class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size()>1)
        {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            
            if(top1 > top2)
                pq.push(top1-top2);
        }
        return pq.empty() ? 0 : pq.top();
    }
};