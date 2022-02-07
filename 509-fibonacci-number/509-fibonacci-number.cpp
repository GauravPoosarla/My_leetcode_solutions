class Solution {
public:
    int fib(int n) {
        // BruteForce
        // TC: O(n)
        // SC: O(1)
        
        int first = 0;
        int second = 1;
        
        if(n<2)
        {
            return n;
        }
        
        int sum=0;
        for(int i=2; i<=n; i++)
        {
            sum = first+second;
            first = second;
            second = sum;
        }
        return second;
    }
};