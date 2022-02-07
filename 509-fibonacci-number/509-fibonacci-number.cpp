class Solution {
public:
    int fib(int n) {
        // BruteForce Iterative
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
        
//         BruteForce Recursive
//         TC: O(n)
//         SC: O(n)
//         if(n<2)
//         {
//             return n;
//         }
        
//         int first = fib(n-1);
//         int second = fib(n-2);
//         return first + second;
    }
};