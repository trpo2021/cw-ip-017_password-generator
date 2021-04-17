#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "num.h"

using namespace std;
int Num(int n, string& Pass, int Mask[], int k)
{
	int temp;
	int* A = new int[k];
	for (int i = 0; i < k; i++) {
		temp = rand() % n;
		A[i] = temp;
	}
	for (int i = 0; i < k; i++) {
		Pass[A[i]] = rand() % 10 + '0';
		Mask[A[i]] = 1;
	}
	delete[] A;
	return 0;
}
