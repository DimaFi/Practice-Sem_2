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
	int i, j, k;
	for (i = 0; i < n; i++) {
		j = n - 1;
		while (j > 0 && comp(a[j], a[j - 1])) {
			swap(a[j], a[j - 1]);
			j--;
		}
		while (j > 0 && comp(a[j], a[j - 1])) {
			swap(a[j], a[j - 1]);
			j--;
		}
	}
}

void choose_sort(people* a, int n) {
	for (int i = 0; i < n; i++) {
		int mind = i;
		for (int j = i + 1; j < n; j++) {
			if (comp(a[j], a[mind])) {
				mind = j;
			}
			else if (comp(a[j], a[mind])) {
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

	bubble(a, n);
	//in_sort(a, n);
	//choose_sort(a, n);

	out << num << endl;

	for (int i = 0; i < n; i++) {
		out << a[i].surname << ' ' << a[i].name << ' ' << a[i].secname << ' ' << a[i].year << ' ' << a[i].p1 << ' ' << a[i].p2 << ' ' << a[i].p3 << ' ' << a[i].p4 << ' ' << a[i].p5 << endl;
	}

	in.close();
	out.close();

}
