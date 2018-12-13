#include "List.h"
const int DEG = 9;

class TPolinom
{
private:
	struct Monom 
	{
		int koef;
		int deg;
		string name;
		Monom(int _k = 1, int _d = 0)
		{
			koef = _k;
			deg = _d;
		}
		Monom operator +(const Monom &mn)
		{
			if (this->deg != mn.deg)
				throw "incorrect addition";
			Monom tmp;
			tmp.koef = this->koef + mn.koef;
			tmp.deg = this->deg;
			tmp.name =this->name;
			return tmp;
		}
		Monom operator -(const Monom &mn)
		{
			if (this->deg != mn.deg)
				throw "incorrect addition";
			Monom tmp;
			tmp.koef = this->koef - mn.koef;
			tmp.deg = this->deg;
			tmp.name = this->name;
			return tmp;
		}
	};
	string prefix;
	TList<Monom> polinom;
	bool IsSign(char op);
	bool IsVariable(char op);
	int GetDegree(char p);
public:
	TPolinom(string _str = "") :prefix(_str) {}
	TPolinom(const TPolinom &pl);
	void Convert();//нужна для преобразования 
	int Calculate(int _x, int _y , int _z);
	TPolinom operator+(TPolinom &pl);
	TPolinom operator-(TPolinom &pl);
	TPolinom& operator=(const TPolinom &pl);
	friend ostream & operator<<(ostream &os, TPolinom &pl);
	friend istream & operator>>(istream &is, TPolinom &pl);
	bool operator == (const TPolinom &pl)const ;
};
