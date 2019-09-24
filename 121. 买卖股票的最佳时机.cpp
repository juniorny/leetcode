class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.empty())
            return 0;

        int len = prices.size();

        int i;
        int dp_i_0 = 0; 
        int dp_i_1 = INT_MIN;
        for (i = 0; i < len; i++)
        {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(-prices[i], dp_i_1);
        }

        return dp_i_0;
    }
};