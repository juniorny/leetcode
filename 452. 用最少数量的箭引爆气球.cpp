/*
无重叠区间变形
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty())
            return 0;
        
        int n = points.size();
        
        sort(points.begin(), points.end(), cmp);
        
        int res = 1;
        int x = points[0][1];
        for (int i = 1; i < n; i++)
        {
            if (x < points[i][0])
            {
                res++;
                x = points[i][1];
            }
        }
        
        return res;
    }
    
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
};