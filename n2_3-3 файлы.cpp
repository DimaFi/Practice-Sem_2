#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n, count = 1;
    double x, xc;
    ofstream inn("input.bin", ios_base::binary);

    cin >> n;

    for (int i = 1; i < n+1; i++) {
        x = 1. / i;
        inn.write((char*)&x, sizeof(double));

    }
    inn.close();

    ifstream fin("input.bin", ios_base::binary);

    while (fin.peek() != EOF) {
        fin.read((char*)&xc, sizeof(double));
        if (count % 3 == 0) {
            cout << xc << '\n';
        }
        count++;
    }
    fin.close();
}
