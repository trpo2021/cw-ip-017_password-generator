#include "libpwgen/Odn.h"
#include "libpwgen/Spec.h"
#include "libpwgen/copy.h"
#include "libpwgen/generate.h"
#include "libpwgen/isint.h"
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
    /* Password setting buttons:
     * numbers-adds numbers to the password
     * registr-adds uppercase letters
     * symbols-adds symbols
     * unambiguity-removes character ambiguity
     * Copy-copies the password to the clipboard
     */
    int numbers, registr, symbols, unambiguity, Copy;
    char r;
    string Pass;
    srand(time(NULL));
    n = inputInt("Password lenght(integer): ");
    cout << "\n";
    numbers = inputInt("Add numbers? 1-true,other-false: ");
    cout << "\n";
    registr = inputInt("Add upper case? 1-true,other-false: ");
    cout << "\n";
    symbols = inputInt("Add special characters? 1-true,other-false: ");
    cout << "\n";
    unambiguity = inputInt("Remove ambiguity? 1-true,other-false: ");
    cout << "\n";

    Mask = new int[n];
    k = n / ((numbers == 1) + (registr == 1) + (symbols == 1) + 1);

    do {
        r = 'n';
        Generate(n, Pass, Mask);
        if (numbers == 1) {
            Num(n, Pass, Mask, k);
        }
        if (registr == 1) {
            Reg(n, Pass, Mask, k);
        }
        if (symbols == 1) {
            Spec(n, Pass, Mask, k);
        }
        if (unambiguity == 1) {
            Odn(n, Pass, Mask);
        }
        cout << Pass << endl;
        for (i = 0; i < n; i++) {
            Mask[i] = 0;
        }
        Copy = inputInt("Copy password? 1-true,other-false: ");
        if (Copy == 1) {
            copy(Pass);
        }
        cout << "To refresh click r" << endl;
        cout << "\n";
        r = getch();
        Pass = "";
    } while (r == 'r');

    return 0;
}
