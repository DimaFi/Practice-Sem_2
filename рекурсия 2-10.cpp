#include <iostream>
#include <algorithm>


using namespace std;
double f(int n, int d) {
	if (d == n) {
		return sqrt(n);
	}
	return sqrt(d+f(n,d+1));
}

int main() {
	double n, d;
	cin >> n;
	d = 1;
	
	cout << n / f(n, d);

	return 0;
}
