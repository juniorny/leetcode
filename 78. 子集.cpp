class Solution {
public:
    /*
    // 迭代解法
    vector<vector<int>> subsets(vector<int>& nums) {           
        vector<vector<int>> res;
        res.push_back({});
        int n = nums.size();
        for (int i = 0; i < n; i++)     // 逐个枚举，空集的幂集只有空集，每增加一个元素，让之前幂集中的每个集合，追加这个元素，就是新增的子集
        {
            int rn = res.size();
            for (int j = 0; j < rn; j++)
            {
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        
        return res;
    }
    
    // 递归解法
    vector<vector<int>> subsets(vector<int>& nums) {           
        if (nums.empty())
            return {{}};

        int tmp = nums.back();
        nums.pop_back();
        vector<vector<int>> res = subsets(nums);    // 拿到去除最后一个元素的集合结果
        int n = res.size();
        for (int i = 0; i < n; i++)
        {
            res.push_back(res[i]);                  //复制原集合
            res[i].push_back(tmp);                  //在原集合上加上最后一个元素
        }

        return res;
    }
    */
    // 位运算
    /*
    数组的每个元素，可以有两个状态：
    1、不在子数组中（用 0 表示）
    2、在子数组中（用 1 表示）
    https://leetcode-cn.com/problems/subsets/solution/hui-su-python-dai-ma-by-liweiwei1419/
    */
    vector<vector<int>> subsets(vector<int>& nums) {           
        int n = 1 << nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < nums.size(); j++)     
            {
                if ((i >> j) & 1)
                    tmp.push_back(nums[j]);
            }
            
            res.push_back(tmp);
        }

        return res;
    }
};