#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

void SmZn(
        int NumClassSimbols, char SimbClassSimbols, std::string& Pass, int cord)
{
    int flag;
    std::string StrPas = "o0OlI15SsZz2";
    char t;
    flag = 0;

    while (flag != 1) {
        t = rand() % NumClassSimbols + SimbClassSimbols;
        flag = 1;
        for (int c = 0; c < 12; c++) {
            if (t == StrPas[c]) {
                flag = 0;
            }
        }
    }
    Pass[cord] = t;
}
