class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		/*使用二维数组表示出了3个信息，可类推表示更多信息*/
		//记录第i行是否出现过数字j
        bool rows[9][9] = {false};
		//记录第i列是否出现过数字j
        bool cols[9][9] = {false};
		//记录第i个方格是否出现过数字j
        bool boxs[9][9] = {false};
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                
                int val = board[i][j] - '1';
                int m = 3 * (i / 3) + j / 3;
                if (rows[i][val] || cols[j][val] || boxs[m][val])
                    return false;
                
                rows[i][val] = true;
                cols[j][val] = true;
                boxs[m][val] = true;
            }
        }
        
        return true;
    }
};