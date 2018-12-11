#include "List.h"
#include <vector>
const int DEG = 9;

class TPolinom
{
private:
	struct Monom 
	{
		double koef;
		int deg;
		Monom(double _k = 0, int _deg = 0)
		{
			koef = _k;
			deg = _deg;
		}
		/*Monom operator +()
		{

		}*/
		friend ostream& operator<<(ostream &os, Monom &mn)
		{
			os << "Степень монома:" << mn.deg << " ";
			os << "Коэфициент монома:" << mn.koef << " " << endl;
			return os;
		}
	};
	int p;
	string str;
	TList<Monom> polinom;
	TList<Monom>::iterator it;
	bool IsSign(char op);
	bool IsVariable(char op);
	int Change_Num_System(int a);
	int GetDegree(char p);
public:
	TPolinom(string _str="");
	void Fill_List();
	void Print()
	{
		cout << polinom;
	}
	TPolinom operator+(TPolinom &pl)
	{
		TPolinom tmp;
		TList<Monom>::iterator it1,it2;
		//if (this->polinom.GetSize() >= pl.polinom.GetSize())
		//{
		//	//tmp = *this;
		//	it1 = this->polinom.Begin();
		//	it2 = pl.polinom.Begin();
		//}
		//else
		//{
		//	it1 = pl.polinom.Begin();
		//	it2 = this->polinom.Begin();
		//}
		////it1 = tmp.polinom.Begin();
		it1 = this->polinom.Begin();
		it2 = pl.polinom.End();
		for (it1,it2;it1!=this->polinom.End(),it2!=pl.polinom.End();)
		{
			if (it1->data.deg == it2->data.deg)
			{
				Monom t(it1->data.koef + it2->data.koef,it1->data.deg);
				tmp.polinom.Push_Back(t);
				++it1;
				++it2;
			}
			if (it1->data.deg > it2->data.deg)
			{
				Monom t(it1->data.koef, it1->data.deg);
				tmp.polinom.Push_Back(t);
			}
			else if (it1->data.deg < it2->data.deg)
			{
				Monom t(it2->data.koef, it2->data.deg);
				++it2;
			}
		}
		return tmp;
	}
};
