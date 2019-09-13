class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();

        for (int i = size - 1; i >= 0; i--)
        {
            if (digits[i] == 9)			//判断等于9就可以操作了
               digits[i] = 0;
            else
            {
                digits[i]++;
                return digits;
            }
        }
        
        if (digits.front() == 0)
            digits.insert(digits.begin(), 1); 

        return digits;
    }
};