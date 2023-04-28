#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct people {
	int year, p1, p2, p3, p4, p5;
	string name, surname, secname;
};

void bubble(people* a, int n) {
	people temp;
	int i, j;
	for (i = 0; i < n; i++) {
		for (i = n; i >= 0; i--) {
			j = i;
			while (a[j].surname < a[j - 1].surname && j > 0) {
				swap(a[j], a[j - 1]);
				j--;
			}
			while (a[j].year > a[j - 1].year&& j > 0 && a[j].surname == a[j - 1].surname) {
				swap(a[j], a[j - 1]);
				j--;
			}
		}
	}
}

void choose_sort(people* mas1, int n) {
	for (int i = 0; i < n; i++) {
		int mind = i;
		for (int j = i + 1; j < n; j++) {
			if (mas1[j].surname < mas1[mind].surname) {
				mind = j;
			}
			else if (mas1[j].surname == mas1[mind].surname && mas1[j].year > mas1[mind].year) {
				mind = j;
			}
		}
		if (mind != i) {
			swap(mas1[i], mas1[mind]);
		}
	}
}

void in_sort(people* mas2, int n) {
	for (int i = 1; i < n; i++) {
		people key = mas2[i];
		int j = i - 1;
		while (j >= 0 && (mas2[j].surname > key.surname || (mas2[j].surname == key.surname && mas2[j].year < key.year))) {
			mas2[j + 1] = mas2[j];
			j = j - 1;
		}
		mas2[j + 1] = key;
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
	cout << n;

	in.clear();
	in.seekg(0);

	in >> num;

	people* a = new people[n];

	for (int i = 0; i < n; i++) {
		in >> a[i].name >> a[i].surname >> a[i].secname >> a[i].year >> a[i].p1 >> a[i].p2 >> a[i].p3 >> a[i].p4 >> a[i].p5;
	}

	bubble(a, n);
	//in_sort(a, n);
	//choose_sort(a, n);

	out << num << endl;

	for (int i = 0; i < n; i++) {
		out << a[i].name << ' ' << a[i].surname << ' ' << a[i].secname << ' ' << a[i].year << ' ' << a[i].p1 << ' ' << a[i].p2 << ' ' << a[i].p3 << ' ' << a[i].p4 << ' ' << a[i].p5 << endl;
	}

	in.close();
	out.close();

}
