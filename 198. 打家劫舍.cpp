/* 
动态规划
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int n = nums.size();
        
        // int *dp = new int[n + 1];
        // dp[0] = 0;
        // dp[1] = nums[0];
        int pre = 0;
        int cur = nums[0];
        for (int i = 2; i <= n; i++)
        {
            // dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
            int tmp = cur;
            cur = max(pre + nums[i - 1], tmp);
            pre = tmp;
        }
        
        // return dp[n];
        return cur;
    }
};