class Solution {
public:
    int reverse(int x) {
/*
        int max = 0x7fffffff;
        int min = 0x80000000;
        
        long long res = 0;  
        while (x != 0)				
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        
        if (res > max || res < min)
            return 0;
        
        return res;
*/
        int res = 0;
        while (x != 0)			//取出每一位的套路
        {
            int tmp = x % 10;		
            x /= 10;
            
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && tmp > 7))	//INT_MAX = 2147483647
                return 0;
            
            if (res < INT_MIN /10 || (res == INT_MIN / 10 && tmp < -8))	//INT_MIN = -2147483648
                return 0;
                
            res = res * 10 + tmp;
        }
        
        cout << INT_MAX << ", " << INT_MIN;
        
        return res;
    }
};