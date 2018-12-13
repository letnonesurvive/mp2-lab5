#include <list>
#include "Polinom.h"
void main()
{
	setlocale(LC_ALL, "ru");
	TPolinom mypl2("x9y9+xy+1"),mypl1("x8y8+x3y3+xy+27"),mypl3;
	mypl1.Convert(); mypl2.Convert();
	cout << mypl1 + mypl2;
}