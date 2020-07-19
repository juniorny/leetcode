/* 
回溯算法：即“深度优先遍历 + 状态重置 + 剪枝”（这道题没有剪枝）
https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        bool visited[len]{false};
        vector<int> tmp;
        
        backtrace(nums, tmp, visited, res);
        
        return res;
        
    }
    
    void backtrace(vector<int> nums, vector<int> tmp, bool visited[], vector<vector<int>>& res)
    {
        if (tmp.size() == nums.size())
        {
            res.push_back(tmp);
            return; 
        }
            
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] == true)
                continue;
            
            visited[i] = true;
            tmp.push_back(nums[i]);
            backtrace(nums, tmp, visited, res);		// 上下对称
            tmp.pop_back();
            visited[i] = false;
        }
    }
    

    
};