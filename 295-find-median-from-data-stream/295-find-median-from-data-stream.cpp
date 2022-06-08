class MedianFinder {
private:
    priority_queue<int> firstQ; // max heap for storing the first half; top will be the max element 
    priority_queue<int, vector<int>, greater<int>> secQ; // min heap for the second half; top element will be minimum of second half, which we need for calculating median.
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(firstQ.empty() or (firstQ.top() > num))
            firstQ.push(num);
        else
            secQ.push(num);
        
        // rebalance the two halfs to make sure the length difference is no larger than 1;
        if(firstQ.size() > secQ.size() + 1)
        {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        else if(firstQ.size() + 1 < secQ.size())
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }
    
    double findMedian() {
        if(firstQ.size() == secQ.size())
            return firstQ.empty() ? 0 : ((firstQ.top() + secQ.top())/2.0);
        else
            return firstQ.size() > secQ.size() ? firstQ.top() : secQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */