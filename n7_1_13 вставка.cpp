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
	int i, j, n;

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
		out << a[i].cour << ' ' << a[i].fam << ' ' << a[i].name << ' ' << a[i].surn << ' ' << a[i].year << ' ' << a[i].n1 << ' ' << a[i].n2 << ' ' << a[i].n3 << ' ' << a[i].n4 << ' ' << a[i].n5 << endl;
	}

	out << endl;

	stud* b = new stud[n];

	for (i = 0; i < n; i++) {
		in >> b[i].cour >> b[i].fam >> b[i].name >> b[i].surn >> b[i].year >> b[i].n1 >> b[i].n2 >> b[i].n3 >> b[i].n4 >> b[i].n5;
	}

	stud a2;
	int lowindex = 0;

	for (i = 0; i < n; i++) {
		j = i;
		for (j = i + 1; j < n; j++) {
			if (b[j].fam[0] < a1.fam[0] && j > 0) {
				a1 = a[j];
				lowindex = j;
			}
		}
		a2 = b[i];
		b[i] = b[lowindex];
		b[lowindex] = a2;
	}

	for (i = 0; i < n; i++) {
		j = i;
		for (j = i + 1; j < n; j++) {
			a1 = b[j];
			if (a1.year > b[j - 1].year && j > 0 && a1.fam[0] == b[j - 1].fam[0]) {
				a1 = b[j];
				lowindex = j;
			}
		}
		a2 = b[i];
		b[i] = b[lowindex];
		b[lowindex] = a2;
	}

	for (i = 0; i < n; i++) {
		out << b[i].cour << ' ' << b[i].fam << ' ' << b[i].name << ' ' << b[i].surn << ' ' << b[i].year << ' ' << b[i].n1 << ' ' << b[i].n2 << ' ' << b[i].n3 << ' ' << b[i].n4 << ' ' << b[i].n5 << endl;
	}

	in.close();
	out.close();
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
//Сделать дз семинар!!!
