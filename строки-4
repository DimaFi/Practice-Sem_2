#include <iostream>
#include <string>

using namespace std;


int ktoi(char s1) {
    int i = s1 - '0';
    return i;
}

int main()
{
    string s;
    int a, sum = 0, n;
    cin >> s;

    n = 0;
    
    sum += ktoi(s[n]);
    n += 2;

    while (n <= s.length()) {
        if (s[n - 1] == '+' && n + 2 != s.length()) {
            sum += ktoi(s[n]);
        }
        if (s[n - 1] == '-' && n + 2 != s.length()) {
            sum -= ktoi(s[n]);
        }
        if (n + 2 != s.length()) {
            n += 2;
        }
    }
    cout << sum;
}
