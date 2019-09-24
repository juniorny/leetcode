class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;
        
        int i = 0;
        int sign = 1;                       // 标记正负号

        while (str[i] == ' ')               // 去除空白字符
            i++;
        
        if (str[i] == '-' || str[i] == '+')
            sign = (str[i++] == '+') ? 1 : -1;
        
        int res = 0;
        while (str[i] != '\0')
        {
//            cout << str[i];
            if (str[i] >= '0' && str[i] <= '9')
            {
				// 2147483647, -2147483648
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] > '7'))
                    return (sign == 1) ? INT_MAX : INT_MIN;
  
                res = 10 * res + (str[i] - '0');
            }
            else
                break;             
            i++;
        }
        
        return res * sign;
    }
};