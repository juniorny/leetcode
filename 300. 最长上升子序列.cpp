/*
动态规划
https://mp.weixin.qq.com/s/EWLi6sP3l4xsuc6GDpQAjw
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            res = max(res, dp[i]);
        }
        
        return res;
    }
};