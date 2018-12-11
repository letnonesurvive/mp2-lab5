#include <list>
#include "Polinom.h"
void main()
{
	setlocale(LC_ALL, "ru");
	TPolinom mypl1("3x5y2z5-5x4y3z3+7x3y5z"),mypl2("4x3y2z6-6x2yz8");
	mypl1.Fill_List();
	mypl2.Fill_List();
	TPolinom tmp;
	tmp = mypl1 + mypl2;
	tmp.Print();
	//mypl2 = mypl1;
	//TList<int> lst1;
	//lst1.Push_Back(5);
	//TList<int> lst2=lst1;
	/*TList<int> lst1, lst2;
	lst1.Push_Back(1);
	lst1.Push_Back(2);
	lst2 = lst1;
	TList<int>::iterator it;
	for (it = lst2.Begin(); it != lst2.End(); ++it)
		cout << *it << endl;*/
	//TList<int>::iterator it;
	//lst.Push_Back(1);
	//lst.Push_Back(2);
	//lst.Push_Back(3);
	//it = lst.Begin();
	//lst.Insert(it, 10);
	////lst.Erase(it);
	//for (it = lst.Begin(); it != lst.End(); ++it)
	//	cout << *it << endl;
	/*list<int> lst1,lst2;
	std::list<int>::iterator it;
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	lst2 = lst1;*/
	/*it = lst.begin();
	++it;
	--it;
	lst.insert(it, 10);
	lst.erase(--it);
	for (it = lst.begin(); it != lst.end(); ++it)
		cout << *it << endl;*/
}