/* 
斐波那契数列，动态规划
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)
           return n;
        
        int n_1 = 2;
        int n_2 = 1;
        int res;
        for (int i = 3; i <= n; i++)
        {
            res = n_1 + n_2;
            n_2 = n_1;
            n_1 = res;
        }
        
        return res;
    }
};