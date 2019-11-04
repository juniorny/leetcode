/* 
动态规划 
dp[i]表示以i结尾的最大子序列和
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int max_sum = nums[0];
        int pre = nums[0];
        
        for (int i = 1; i < n; i++)
        {
            if (nums[i] + pre > nums[i])	// 第i个数获得dp[i-1]的正收益，就加上
                pre = nums[i] + pre;
            else
                pre = nums[i];				// 否则是dp[i-1]拖累了，保持本身就好
            
            max_sum = max(max_sum, pre);
        }
        
        return max_sum;
        
    }
};