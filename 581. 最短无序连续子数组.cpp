/* 
正序遍历一次，逆序遍历一次
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int len = nums.size();
        int right = 0;
        int left = len - 1;
        int max = nums[0];
        int min = nums[len - 1];
		// 正序遍历确定right左边的需要重排
        for (int i = 1; i < len; i++)
        {
            if (nums[i] >= max)
                max = nums[i];
            else
                right = i;
        }
        // 逆序遍历确定left右边的需要重排
        for (int i = len - 2; i >= 0; i--)
        {
            if (nums[i] <= min)
                min = nums[i];
            else
                left = i;
        }
        
        return (left < right) ? right - left + 1 : 0;
    }
};