class Solution {
public:
    bool isValid(string s) {
        
        int len = s.size();
        if (len % 2 != 0)
            return false;
        
        stack<char> st;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;
                
                char top = st.top();
                if (s[i] > top && s[i] - top <= 2)  // ()相差1，{}[]相差2
                {
                    st.pop();
                    continue;
                }
                
                return false;
            }
        }
        
        return st.empty();
    }
};