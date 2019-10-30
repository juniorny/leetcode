class Solution {
public:
	// KMP算法
	
	//getNext函数类似匹配串的KMP过程
    void getNext(string s, int *next)
    {
        next[0] = -1;
        int i = 0;
        int j = -1;

        while (i < s.size())
        {
            if (j == -1 || s[i] == s[j])
            {
                i++;
                j++;
                next[i] = j;
            }
            else
                j = next[j];
        }
    }


int KMP(string s, string p, int *next)
{
    
    getNext(p, next);
		
	int s_len = s.size();
	int p_len = p.size();
	
	int i = 0;
	int j = 0;
	
	while (i < s_len && j < p_len)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	
	if (j == p_len)
		return i - j;
		
	return -1;
}
    
    int strStr(string haystack, string needle) {
        
        if (needle.empty())
            return 0;
        
        int hlen = haystack.size();
        int nlen = needle.size();
        int *next = new int[nlen + 1];
        
        int res = KMP(haystack, needle, next);
        
        delete []next;
        
        return res;
        
        
    /*  
		// 暴力解法 
        int hlen = haystack.size();
        int nlen = needle.size();
        
        if (hlen < nlen)
            return -1;
        
        int res = 0;
        int i, j, k;
        for (i = 0; i < hlen - nlen + 1; i++)
        {
            if (haystack[i] == needle[0])
            {
                for (j = i + 1, k = 1; k < nlen; j++, k++)
                {
//                    cout << needle[k];
                    if (haystack[j] != needle[k])
                        break;
                }
                if (k == nlen)
                    return i;
            }
        }
        
        return -1;
    */
    }
};