#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h> 
#include <string>
#include <ctime>
#include <vector>
#include <conio.h>

using namespace std;

int main()
{
	int k, n, * Mask, i;
	int b1, b2, b3, b4;
	char r;
	string Pass;
	srand(time(NULL));
	cout << "Кол-во символов в пароле:";
	cin >> n;
	cout << "\n";
	cout << "Добавить цифры? 1/0 ";
	cin >> b1;
	cout << "\n";
	cout << "Добавить ВеРхНиЙ РеГиСтР? 1/0 ";
	cin >> b2;
	cout << "\n";
	cout << "Добавить $пеци@льные символы? 1/0 ";
	cin >> b3;
	cout << "\n";
	cout << "Убрать неоднозначность? 1/0 ";
	cin >> b4;
	cout << "\n";

	Mask = new int[n];
	k = n / (b1 + b2 + b3 + 1);

	do {
		r = 'n';
		Generate(n, Pass, Mask);
		if (b1 == 1) { Num(n, Pass, Mask, k); }
		if (b2 == 1) { Reg(n, Pass, Mask, k); }
		if (b3 == 1) { Spec(n, Pass, Mask, k); }
		if (b4 == 1) { Odn(n, Pass, Mask); }
		cout << Pass << endl;
		Pass = "";
		for (i = 0; i < n; i++) {
			Mask[i] = 0;
		}
		cout << "чтобы обновить нажмите r" << endl;
		cout << "\n";
		r = getch();
	} while (r == 'r');

	return 0;
}