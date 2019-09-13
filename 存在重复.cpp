class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
/*
        map<int, bool>table;
        
        if (nums.empty())
            return false;
        
        table[nums[0]] = true;
        for (int i = 1; i < nums.size(); i++)
        {
            if (table[nums[i]])
                return true;
            else
            {
                table[nums[i]] = true;
            }
        }
        return false;
*/
		//利用set容器唯一性，insert一个已存在值时返回false
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            pair<set<int>::iterator, bool> ret = s.insert(nums[i]);
            if (ret.second == false)
                return true;
        }
        return false;
    }
};