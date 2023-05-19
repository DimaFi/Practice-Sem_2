#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct people {
	int year, p1, p2, p3, p4, p5;
	string name, surname, secname;
};

bool comp(people s1, people s2) {
	if (s1.surname > s2.surname) {
		return 1;
	}
	else if (s1.surname == s2.surname && s1.year > s2.year) {
		return 1;
	}
	else {
		return 0;
	}
}


void bubble(people* a, int n) {
	people temp;
	int j, k;
	for (int i = 0; i < n-1; i++) {
		for (int j = n - 1; j > i;j--) {
			if (comp(a[j-1], a[j])) {
				swap(a[j], a[j - 1]);
			}
		}
	}
}

void choose_sort(people* a, int n) {
	for (int i = 0; i < n; i++) {
		int mind = i;
		for (int j = i + 1; j < n; j++) {
			if (comp(a[mind], a[j])) {
				mind = j;
			}
		}
		if (mind != i) {
			swap(a[i], a[mind]);
		}
	}
}

void in_sort(people* a, int n) {
	for (int i = 1; i < n; i++) {
		people key = a[i];
		int j = i - 1;
		while (j >= 0 && comp(a[j], key)) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}


ifstream in("input.txt");
ofstream out("output.txt");

int main() {

	int num, n = 0;
	string ss;

	while (in.peek() != EOF) {
		getline(in, ss, '\n');
		n++;
	}
	n--;

	//cout << n;

	in.clear();
	in.seekg(0);

	in >> num;

	people* a = new people[n];

	for (int i = 0; i < n; i++) {
		in >> a[i].surname >> a[i].name >> a[i].secname >> a[i].year >> a[i].p1 >> a[i].p2 >> a[i].p3 >> a[i].p4 >> a[i].p5;
	}

	for (int i = 0; i < n; i++) {
		out << a[i].surname << ' ' << a[i].name << ' ' << a[i].secname << ' ' << a[i].year << ' ' << a[i].p1 << ' ' << a[i].p2 << ' ' << a[i].p3 << ' ' << a[i].p4 << ' ' << a[i].p5 << endl;
	}

	out << endl;

	//bubble(a, n);
	//in_sort(a, n);
	choose_sort(a, n);

	out << num << endl;

	for (int i = 0; i < n; i++) {
		out << a[i].surname << ' ' << a[i].name << ' ' << a[i].secname << ' ' << a[i].year << ' ' << a[i].p1 << ' ' << a[i].p2 << ' ' << a[i].p3 << ' ' << a[i].p4 << ' ' << a[i].p5 << endl;
	}

	in.close();
	out.close();

}


/*141
Dash Dima Pan 2001 3 4 3 4 5
Bank Nikolay Gyn 1995 3 4 3 4 3
Info Kokya Uio 2000 3 3 3 4 5
Gihu Dima Pan 2011 3 4 3 4 3
Banka Nikolay Gyn 1996 3 4 3 4 3
Andreev Lui Pan 2005 2 2 2 2 2
Dash Dima Oui 2003 3 4 3 4 5
Andreeva Lui Pan 2004 2 2 2 2 2
*/
