#include "generate.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int Generate(int n, string& Pass, int Mask[])
{
    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        A[i] = i;
        Pass.append(1, rand() % 26 + 'a');
        Mask[A[i]] = 0;
    }
    delete[] A;
    return 0;
}
