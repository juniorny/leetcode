class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>m;
        vector<int> res;
        int size = nums.size();
        
        for (int i = 0; i < size; i++)
        {
            int tmp = target - nums[i];
            if (m.count(tmp) && m[tmp] != i)	// m.count(key)方法可以判断key在不在map里
            {
                res.push_back(i);
                res.push_back(m[tmp]);
                break;
            }
            m[nums[i]] = i;
        }
      
        return res;
    }
};