#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Spec.h"

using namespace std;

int Spec(int n, string& Pass, int Mask[], int k) {
	string s, s_2;
	s = "!@#$%^&*()-_+=/?|~[]{}";
	int i, count = 0, * UkA, * UkB;

	for (i = 0; i < k; i++) {
		s_2 += s[rand() % 23];
	}
	for (i = 0; i < n; i++) {
		if (Mask[i] == 0) {
			count++;
		}
	}

	int temp = 0;
	UkA = new int[count];
	for (i = 0; i < n; i++) {
		if (Mask[i] == 0) {
			UkA[temp] = i;
			temp++;
		}
	}
	UkB = new int[k];
	for (i = 0; i < k; i++) {
		UkB[i] = UkA[rand() % count-1];
	}
	for (i = 0; i < k; i++) {
		Mask[UkB[i]] = 3;
	}
	for (i = 0; i < k; i++) {
		Pass[UkB[i]] = s_2[i];
	}
	return 0;
}