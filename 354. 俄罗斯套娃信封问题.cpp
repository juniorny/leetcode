/*
1、宽度升序排序，宽相等的长降序排序
2、求排序后的长度数组最长上升子序列
*/

class Solution {
public: 
	//自定义比较函数写在类中需要加static，或者写在类外作全局函数
    static bool cmp(vector<int> a, vector<int> b)	// 注意二维数组的比较的写法，多维以此类推
    {
        if (a[0] == b[0]) 
           return a[1] > b[1];
        
        return a[0] < b[0]; 
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        if (envelopes.empty())
            return 0;
        
        int n = envelopes.size();
        
        sort(envelopes.begin(), envelopes.end(), cmp);
         
        int height[n];
        for (int i = 0; i < n; i++)
            height[i] = envelopes[i][1];
        
        
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (height[i] > height[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
            res = max(res, dp[i]);
        
        return res;
    }
};