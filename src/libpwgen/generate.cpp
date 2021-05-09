#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "generate.h"

using namespace std;

int Generate(int n, string& Pass, int Mask[])
{
	int temp;
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		temp = i;
		A[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		Pass.append(1, rand() % 26 + 'a');
		Mask[A[i]] = 0;
	}
	delete[] A;
	return 0;
}
