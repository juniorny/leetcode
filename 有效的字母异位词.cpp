class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size())
            return false;
        
        map<char, int>mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second != 0)
                return false;
        }
        
        return true;
    }
};