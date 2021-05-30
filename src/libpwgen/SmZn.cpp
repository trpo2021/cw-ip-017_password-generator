#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

void SmZn(int i, char p, std::string& Pass, int cord)
{
    int fl;
    std::string O = "o0OlI15SsZz2";
    char t;
    fl = 0;

    while (fl != 1) {
        t = rand() % i + p;
        fl = 1;
        for (int c = 0; c < 12; c++) {
            if (t == O[c]) {
                fl = 0;
            }
        }
    }
    Pass[cord] = t;
}
