/* 
给以数组元素为索引的位置加N,如果第二次扫描的时候，元素值小于N，就说明没有给这个位置加过N。说明原数组里面没有对应这个位置的数，所以push这个位置。 
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty())
            return nums;
        
        int n = nums.size();        
        vector<int> res;
        
        for (int i = 0; i < n; i++)
        {
            int index = (nums[i] - 1) % n;
            nums[index] += n;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= n)
                res.push_back(i + 1);
        }
       
        return res;
    }
};