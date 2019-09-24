//此类题就考虑双指针解法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j;
        int size = nums.size();
        for (i = 0, j = 0; i < size; i++)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        
        for (i = j; i < size; i++)
            nums[i] = 0;
    }
};