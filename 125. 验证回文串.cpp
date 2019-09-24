class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (!isdigit(s[i]) && !isalpha(s[i]) && i < j)
                i++;
            
            while (!isdigit(s[j]) && !isalpha(s[j]) && i < j)
                j--;
            
            if (i < j)
            {
                if (tolower(s[i]) != tolower(s[j]))
                    return false; 
                i++;
                j--;
            }
        }
        
        return true;
    }
};