class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int count = 1;
        int num = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (count == 0)
                num = nums[i];
            
            count += (num == nums[i]) ? 1 : -1;
        }
        
        return num;
    }
};