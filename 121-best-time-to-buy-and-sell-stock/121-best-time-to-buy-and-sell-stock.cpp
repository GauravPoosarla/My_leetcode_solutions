class Solution {
public:
    int maxProfit(vector<int>& prices) {
//         Brute Force
//             TC: O(n^2)
//             SC: O(1)
//             int maxProf = 0, tempMax = 0;
        
//             for(int i=0; i<prices.size()-1; i++)
//             {
//                  for(int j=i+1; j<prices.size(); j++)
//                  {
//                      tempMax = prices[j] - prices[i];
//                      maxProf = max(tempMax, maxProf);
//                  }
//             }
//          return maxProf;
            
        int minPrice = prices[0], maxProf = 0;
        
        for(int i=0; i<prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;
            maxProf = max(maxProf, profit);
        }
        return maxProf;
    }
};