class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, product = 1;
        while(n > 0)
        {
            int last = n % 10;
            sum += last;
            product *= last;
            n = n/10;
            cout << sum << " " << product << endl;
        }
        return product - sum;
    }
};