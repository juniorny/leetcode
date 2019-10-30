/* 
将两个数异或，转成：求一个数二进制1的个数
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        
        int res = 0;
        while (tmp != 0)
        {
            tmp &= (tmp - 1);	// 将这个数-1和自身&，低位1将变0
            res++;
        }
        
        return res;
    }
};