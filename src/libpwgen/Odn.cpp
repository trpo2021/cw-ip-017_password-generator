#include "Odn.h"
#include "Vibor.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int Odn(int PassLenth, string& Pass, int Mask[])
{ // o=0=O l=I=1 5=S=s Z=z=2
    int i, j;
    srand(time(NULL));
    for (i = 0; i < PassLenth; i++) {
        for (j = 0; j < 12; j++) {
            Vibor(i, j, Pass, Mask);
        }
    }
    return 0;
}
