#include <iostream>
#include <string>
#include <vector>
#include <reg.h>
using namespace std;

int Reg(int n, string& Pass, int Mask[], int k) {
	int Kzero = 0;
	int doptemp2, doptemp, temp = 0;


	for (int i = 0; i < n; i++) {
		if (Mask[i] == 0) {
			Kzero++;
		}
	}
	vector <int> doubleIndexMas(Kzero);
	vector <int> IndexMas(Kzero);
	vector <int> A(k);
	for (int i = 0; i < n; i++) {
		if (Mask[i] == 0) {
			IndexMas[temp] = i;
			temp++;
		}
	}
	for (int j = 0; j < Kzero; j++) {
		doubleIndexMas[j] = j;
	}
	for (int j = 0; j < k; j++) {
		doptemp = rand() % Kzero;
		A[j] = doptemp;
	}
	for (int j = 0; j < k; j++) {
		doptemp2 = IndexMas[A[j]];

		A[j] = doptemp2;
		Pass[A[j]] = rand() % 26 + 'A';
		Mask[A[j]] = 2;
	}
	return 0;
}