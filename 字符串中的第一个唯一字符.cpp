class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> table;
        int len = s.length();
        for (int i = 0; i < len; i++)	//第一遍遍历统计
        {
            table[s[i]]++;
        }
        
        for (int i = 0; i < len; i++)	//第二遍遍历找最小
        {
            if (table[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};