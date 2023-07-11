class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0; // buy stock
        int right = 1; // sell stock
        int maxProfit = 0;

        while( right < prices.size() ){
            // check if the pointers are at profit or not
            if( prices[left] < prices[right] ){
                
                int profit = prices[right] - prices[left];
                // calculating maxProfit by iterating right pointer
                maxProfit = max(profit,maxProfit);
            }
            else{
                left = right; 
                // if the right pointer is less, than move left to right, we have to buy only from low
            }
            right++; // alwys increment right, in case there is else maxProfit
        }
        return maxProfit;
    }
};
