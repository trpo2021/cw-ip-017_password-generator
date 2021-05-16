#include "libpwgen/Odn.h"
#include "libpwgen/isint.h"
#include "libpwgen/Spec.h"
#include "libpwgen/copy.h"
#include "libpwgen/generate.h"
#include "libpwgen/num.h"
#include "libpwgen/reg.h"
#include <conio.h>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;


int main()
{
    int k, n, *Mask, i;
    int b1, b2, b3, b4, b5;
    char r;
    string Pass;
    srand(time(NULL));
    n = inputInt("Password lenght(integer): ");
    cout << "\n";
    b1 = inputInt("Add num? 1-true,other-false: ");
    cout << "\n";
    b2 = inputInt("Add upper case? 1-true,other-false: ");
    cout << "\n";
    b3 = inputInt("Add special characters? 1-true,other-false: ");
    cout << "\n";
    b4 = inputInt("Remove ambiguity? 1-true,other-false: ");
    cout << "\n";

    Mask = new int[n];
    k = n / ((b1==1) + (b2==1) + (b3==1) + 1);

    do {
        r = 'n';
        Generate(n, Pass, Mask);
        if (b1 == 1) {
            Num(n, Pass, Mask, k);
        }
        if (b2 == 1) {
            Reg(n, Pass, Mask, k);
        }
        if (b3 == 1) {
            Spec(n, Pass, Mask, k);
        }
        if (b4 == 1) {
            Odn(n, Pass, Mask);
        }
        cout << Pass << endl;
        for (i = 0; i < n; i++) {
            Mask[i] = 0;
        }
        b5 = inputInt("Copy password? 1-true,other-false: ");
        if (b5 == 1) {
            copy(Pass);
        }
        cout << "To refresh click r" << endl;
        cout << "\n";
        r = getch();
        Pass = "";
    } while (r == 'r');

    return 0;
}