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
		if (this->polinom.GetSize() >= pl.polinom.GetSize())
		{
			tmp = *this;
			it2 = pl.polinom.Begin();
		}
		else
		{
			tmp = pl;
			it2 = this->polinom.Begin();
		}
		it1 = tmp.polinom.Begin();
		for (it1;it1!=tmp.polinom.End();++it1)
		{
			if (it1->data.deg == it2->data.deg)
			{
				it1->data.koef += it2->data.koef;
				++it2;
			}
			else
			{
				tmp.polinom.Insert(it1, it2->data);
			}
			return tmp;
		}
	}
};
