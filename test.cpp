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
    while (s[i] != '.' && s[i] != '\0')
    {
        num = 10 * num + (s[i] - '0');
        i++;
    }

    if (s[i] == '.')
        i++;

    while (s[i] != '\0')
    {
        num2 = 10 * num2 + (s[i] - '0');
        count++;
        i++;
    }

//    cout << num << ' ' << num2 << endl;

    float res = num + num2 / pow(10, count);

    cout << res << endl;

    return 0;
}
