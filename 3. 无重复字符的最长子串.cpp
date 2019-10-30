class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
      /*  
        unordered_map<char, int> umap;
        
        int n = s.size();
        
        int res = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (!umap.count(s[i]))  // map中没有时
                umap[s[i]] = i;
            else
            {
                if (umap[s[i]] < start)
                {
                    umap[s[i]] = i;
                    continue;
                }
                res = max(i - start, res);
                start = umap[s[i]] + 1;
                umap[s[i]] = i;
            }
        }
        
        res = max(res, n - start);
        
        return res;
      */
        
        // 滑动窗口
        unordered_set<char> uset;
        
        int n = s.size();
        int res = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            while (uset.find(s[i]) != uset.end())
            {
                uset.erase(s[start]);
                start++;
            }
            res = max(res, i - start + 1);
            uset.insert(s[i]);
        }
        
        return res;
    }
};