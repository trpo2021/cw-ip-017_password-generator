#include "Odn.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int Odn(int n, string& Pass, int Mask[])
{ // o=0=O l=I=1 5=S=s Z=z=2
    int i, j, fl = 0;
    char t;
    // int* Mask_2 = new int[n];
    string O = "o0OlI15SsZz2";
    for (i = 0; i < n; i++) {
        for (j = 0; j < 12; j++) {
            if (Pass[i] == O[j]) {
                switch (Mask[i]) {
                case 1: {
                    while (fl != 1) {
                        t = rand() % 10 + '0';
                        fl = 1;
                        for (int c = 0; c < 12; c++) {
                            if (t == O[c]) {
                                fl = 0;
                            }
                        }
                    }
                    Pass[i] = t;
                    fl = 0;
                    break;
                }
                case 2: {
                    while (fl != 1) {
                        t = rand() % 26 + 'A';
                        fl = 1;
                        for (int c = 0; c < 12; c++) {
                            if (t == O[c]) {
                                fl = 0;
                            }
                        }
                    }
                    Pass[i] = t;
                    fl = 0;
                    break;
                }
                case 0: {
                    while (fl != 1) {
                        t = rand() % 26 + 'a';
                        fl = 1;
                        for (int c = 0; c < 12; c++) {
                            if (t == O[c]) {
                                fl = 0;
                            }
                        }
                    }
                    Pass[i] = t;
                    fl = 0;
                    break;
                }
                }
            }
        }
    }
    return 0;
}
