#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int num = 0;
    int num2 = 0;
    int count = 0;
    unsigned int i = 0;
    int sign = 1;

    while (s[i] == ' ')
        i++;

    if (s[i] == '-' || s[i] == '+')
        sign = (s[i++] == '+') ? 1 : -1;

    while (s[i] != '.' && s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = 10 * num + (s[i] - '0');
            i++;
        }
        else
        {
            cout << num * sign << endl;
            return 0;
        }
    }

    if (s[i] == '.')
        i++;

    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num2 = 10 * num2 + (s[i] - '0');
            count++;
            i++;
        }
        else
        {
            break;
        }
    }

    cout << (num + (float)num2 / pow(10, count)) * sign << endl;
    return 0;
}
