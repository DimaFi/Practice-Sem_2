#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


void f(int n) {
    for (int i = 0; i < n; i++) {
        cout << '*';
    }
    cout << endl;
    if (n > 1) {
        f(n - 1);
    }
}

int main()
{
    int n;

    cin >> n;

    f(n);
}
