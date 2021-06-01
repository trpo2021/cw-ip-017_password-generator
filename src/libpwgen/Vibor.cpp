#include "SmZn.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

void Vibor(int i, int j, std::string& Pass, int Mask[])
{
    std::string StrPas = "o0OlI15SsZz2";

    if (Pass[i] == StrPas[j]) {
        switch (Mask[i]) {
        case 1: {
            SmZn(10, '0', Pass, i);
            break;
        }
        case 2: {
            SmZn(26, 'A', Pass, i);
            break;
        }
        case 0: {
            SmZn(26, 'a', Pass, i);
            break;
        }
        }
    }
}
