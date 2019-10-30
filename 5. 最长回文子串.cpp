/* 题解：
https://leetcode-cn.com/problems/longest-palindromic-substring/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-bao-gu/
将字符串翻转，转化成求最长公共子串问题，用动态规划解，需要注意<下标对应>条件
通过观察发现，一列数据只与前一列数据有关，可优化空间复杂度
*/
class Solution {
public:
/*
    string longestPalindrome(string s) {
        if (s.empty())
            return s;
        
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        int n = s.size();

        int **dp = new int*[n];
        
        for (int i = 0; i < n; i++)
            dp[i] = new int[n]{0};
        
        int max = 0;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[i] == rs[j])
                {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i - 1][j - 1] + 1;   
                }
                
                if (max < dp[i][j])
                {
                    int beforeRev = n - j - 1;
                    if (beforeRev + dp[i][j] - 1 == i)
                    {
                        max = dp[i][j];
                        end = i; 
                    }                   
                }
            }
        }
        
        for (int i = 0; i < n; i++)
            delete []dp[i];
        delete []dp;
        
        return s.substr(end - max + 1, max);
    }
*/
	//优化了空间复杂度
    string longestPalindrome(string s) {
        if (s.empty())
            return s;
        
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        int n = s.size();

        int *dp = new int[n];
        
        int max = 0;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[i] == rs[j])
                {
                    if (i == 0 || j == 0)
                        dp[j] = 1;
                    else
                        dp[j] = dp[j - 1] + 1;   
                }
                else
                    dp[j] = 0;
                
                if (max < dp[j])
                {
                    int beforeRev = n - j - 1;
                    if (beforeRev + dp[j] - 1 == i)
                    {
                        max = dp[j];
                        end = i; 
                    }                   
                }
            }
        }
        

        delete []dp;
        
        return s.substr(end - max + 1, max);
    }
};