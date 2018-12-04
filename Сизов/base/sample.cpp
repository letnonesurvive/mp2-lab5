#include <cstdlib>
#include "List.h"
void main()
{
	TList<int> a;
	a.Push_Back(1);
	a.Push_Back(2);
	TList<int>::iter it;
	it = a.Begin();
	cout << *(it);
}