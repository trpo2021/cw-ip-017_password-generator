#include "libpwgen/Odn.h"
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
    cout << "Password lenght:";
    cin >> n;
    cout << "\n";
    cout << "Add num? 1/0 ";
    cin >> b1;
    cout << "\n";
    cout << "Add upper case? 1/0 ";
    cin >> b2;
    cout << "\n";
    cout << "Add special characters? 1/0 ";
    cin >> b3;
    cout << "\n";
    cout << "Remove ambiguity? 1/0 ";
    cin >> b4;
    cout << "\n";

    Mask = new int[n];
    k = n / (b1 + b2 + b3 + 1);

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
        cout << "Copy password? 1/0\n";
        cin >> b5;
        b5 = 0;
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