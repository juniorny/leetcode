//双指针解法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, p;
        
        if (nums.empty())
            return 0;
        
        for (i = 1, p = 0; i < nums.size(); i++)
        {
            if (nums[i] != nums[p])
            {
                p++;
                nums[p] = nums[i];   
            }
        }
        
        return p + 1;
    }
};