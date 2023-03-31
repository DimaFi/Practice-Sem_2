#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct stud {
	string name, surn, fam;
	int cour, year, n1, n2, n3, n4, n5;
};


int main()
{
	int i, j, n, min = 999;

	in >> n;

	stud* a = new stud[n];

	for (i = 0; i < n; i++) {
		in >> a[i].cour >> a[i].fam >> a[i].name >> a[i].surn >> a[i].year >> a[i].n1 >> a[i].n2 >> a[i].n3 >> a[i].n4 >> a[i].n5;
	}

	stud a1;

	for (i = 1; i < n; i++) {
		j = i;
		while (a[j].fam[0] < a[j - 1].fam[0] && j > 0) {
			a1 = a[j];
			a[j] = a[j - 1];
			a[j - 1] = a1;
			j--;
		}
		while (a[j].year > a[j - 1].year && j > 0 && a[j].fam[0] == a[j - 1].fam[0]) {
			a1 = a[j];
			a[j] = a[j - 1];
			a[j - 1] = a1;
			j--;
		}
	}

	for (i = 0; i < n; i++) {
		out << a[i].cour << a[i].fam << a[i].name << a[i].surn << a[i].year << a[i].n1 << a[i].n2 << a[i].n3 << a[i].n4 << a[i].n5 << endl;
	}

	out << endl;
	j = 0;
	for (i = 0; i < n; i++) {
		int max = 1;
		int mx = 0;
		for (int i1 = i; i1 < n; i1++)
			if (a[i1].year > max) {
				mx = i1;
				max = a[i1].year;
			}
		a1 = a[mx];
		a[mx] = a[j];
		a[j] = a1;
		j++;

	}
	j = 0;
	for (i = 0; i < n; i++) {
		min = 100;
		int mn = 0;
		for (int i1 = i; i1 < n; i1++)
			if (a[i1].fam[0] < min) {
				mn = i1;
				min = a[i1].fam[0];
			}
		a1 = a[mn];
		a[mn] = a[j];
		a[j] = a1;
		j++;

		int j1 = j;
		for (int ii = j1; ii < n; ii++) {
			int max = 1;
			int mx = 0;
			for (int ii1 = ii; ii1 < n; ii1++)
				if (a[ii1].year > max) {
					mx = ii1;
					max = a[ii1].year;
				}
			a1 = a[mx];
			a[mx] = a[j1];
			a[j1] = a1;
			j1++;

		}
	}

	for (i = 0; i < n; i++) {
		out << a[i].cour << a[i].fam << a[i].name << a[i].surn << a[i].year << a[i].n1 << a[i].n2 << a[i].n3 << a[i].n4 << a[i].n5 << endl;
	}

	in.close();
	out.close();

	return 0;
}

/*
8
141 Dash Dima Pan 2001 3 4 3 4 5
141 Bank Nikolay Gyn 1995 3 4 3 4 3
141 Info Kokya Uio 2000 3 3 3 4 5
141 Gihu Dima Pan 2011 3 4 3 4 3
141 Banka Nikolay Gyn 1996 3 4 3 4 3
141 Andreev Lui Pan 2005 2 2 2 2 2
141 Dash Dima Oui 2003 3 4 3 4 5
141 Andreeva Lui Pan 2004 2 2 2 2 2
*/
