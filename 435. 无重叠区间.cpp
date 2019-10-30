/*
对区间结束时间进行排序
https://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247484319&idx=1&sn=49a9e82e93fe29eb934d9a618be57174&chksm=fb3363ddcc44eacb57d1be9e1e754a6238870a3c4c126a0be133232c4f7458aaffdaec40c0c8&scene=21#wechat_redirect
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
            
        sort(intervals.begin(), intervals.end(), cmp);
        
        int n = intervals.size();
        
        int res = 1;
        int x = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= x)
            {
                res++;
                x = intervals[i][1];
            }
        }
        
        return n - res;
    }
    
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }   
    
};