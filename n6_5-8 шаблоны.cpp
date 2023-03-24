#include <iostream>

using namespace std;

template <typename x> void arrcin(x** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        a[i] = new x[m];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}


template <typename x> void arrcout(x **p, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << p[i][j] << ' ';
        }
        cout << endl;
    }
}

template <typename x> int count_2(x** p, int n, int m, int a, int b) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (p[i][j] < a || p[i][j] > b) {
                count += 1;
            }
                
        }
    }
    return count;
}


int main()
{
    int n, a, b;

    cin >> n >> a >> b;

    int** p = new int* [n];


    arrcin(p, n, n);

    cout << count_2(p, n, n, a, b) << endl;

    arrcout(p, n, n);
  
}
