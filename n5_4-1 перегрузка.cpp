#include <iostream>
#include <algorithm>


using namespace std;

double func(double x) {
	if (x >= 0) {
		if (x >= 0.9) {
			return 1/(0.1 + x) * (0.1 + x);
		}
		return 0.2*x + 0.1;
	}
	return x*x + 0.2;
}
void func(double x, double& a) {
	if (x < 0)
		a = x * x + 0.2;
	if (x >= 0 && x < 0.9)
		a = 0.2 * x + 0.1;
	if (x >= 0.9)
		a = 1 / (0.1 + x) * (0.1 + x);
}

int main() {
	double a, b, h, a1;
	cin >> a >> b >> h;

	for (double i = min(a, b); i <= max(a, b); i += h) {
		cout << i << ' ' << func(i) << endl;
		func(i, a1);
		cout << i << ' ' << a1 << '\n';
	}
	return 0;
}
