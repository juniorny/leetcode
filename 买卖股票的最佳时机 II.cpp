//贪心算法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int tmp = prices[i] - prices[i - 1];
            if (tmp > 0)
                max += tmp;
        }
        
        return max;
    }
};