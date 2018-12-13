#include "Polinom.h"

bool TPolinom::IsSign(char op)
{
	if (op == '+' || op == '-')
		return true;
	else return false;
}

bool TPolinom::IsVariable(char op)
{
	if (op == 'x' || op == 'y' | op == 'z')
		return true;
	else return false;
}

int TPolinom::GetDegree(char p)
{
	if (int(p) > 49 && int(p) < 58)
		return int(p - 48);
	else return 1;
}

TPolinom::TPolinom(const TPolinom & pl)
{
	this->prefix = pl.prefix;
	this->polinom = pl.polinom;
}

void TPolinom::Convert()
{
	int begin = 0;
	bool sign = true;
	Monom mn;
	string num;
	TList<Monom>::iterator it;
	for (int i = 0; i < prefix.size(); i++)
	{
		mn = {};
		if (prefix[i] == '+')
		{
			sign = true;
			i++;
		}
		else if (prefix[i] == '-')
		{
			sign = false;
			i++;
		}
		if (!IsSign(prefix[i]) && !IsVariable(prefix[i]))//если не переменная и не знак(считывание коэфициента перед мономом)
		{
			while (!IsVariable(prefix[i]) && i != prefix.size() && !IsSign(prefix[i]))//пока не встретим переменную x y z 
			{
				num += prefix[i];
				i++;
			}
			mn.koef = atof(num.c_str());
			num = "";
			if (!sign)
				mn.koef = mn.koef*(-1);
		}
		begin = i;
		if (IsVariable(prefix[i]))
		{
			int x = 0, y = 0, z = 0, sum;
			while (!IsSign(prefix[i]) && i != prefix.size())
			{
				switch (prefix[i])
				{
				case 'x':
				{
					x = GetDegree(prefix[i + 1]);
					i++;
					break;
				}
				case 'y':
				{
					y = GetDegree(prefix[i + 1]);
					i++;
					break;
				}
				case 'z':
				{
					z = GetDegree(prefix[i + 1]);
					i++;
					break;
				}
				default:
					i++;
				}
			}
			i--;
			sum = x * 100 + y * 10 + z;
			mn.name = prefix.substr(begin, i-begin+1);
			mn.deg = sum;
		}
		if (polinom.IsEmpty())
		{
			polinom.Push_Back(mn);
			continue;
		}
		for (it = polinom.Begin(); it != polinom.End(); ++it)
		{
			if (mn.deg == it->data.deg)
			{
				it->data.koef = it->data.koef + mn.koef;
				if (it->data.koef == 0)
					polinom.Erase(it);
				break;
			}
			if (mn.deg > it->data.deg)
			{
				polinom.Insert(it, mn);
				break;
			}
		}
		if (it == polinom.End())
			polinom.Push_Back(mn);
	}
}

int TPolinom::Calculate(int _x, int _y, int _z)
{
	int result = 0;
	for (auto it = polinom.Begin(); it != polinom.End();++it)
	{
		int x = it->data.deg / 100, y = (it->data.deg / 10) % 10, z = it->data.deg % 10;
		result += (pow(_x, x) * pow(_y, y) * pow(_z, z))*it->data.koef;
	}
	return result;
}

TPolinom TPolinom::operator+(TPolinom & pl)
{
	if (this->polinom.IsEmpty() || pl.polinom.IsEmpty())
		throw "lists is empty, call method Convert";
	TPolinom main, side, result;
	TList<Monom>::iterator it1, it2;
	if (this->polinom.GetSize() >= pl.polinom.GetSize())
	{
		main = *this;
		side = pl;
		it1 = this->polinom.Begin();
		it2 = pl.polinom.Begin();
	}
	else
	{
		main = pl;
		side = *this;
		it1 = pl.polinom.Begin();
		it2 = this->polinom.Begin();
	}
	for (it1; it1 != main.polinom.End();)
	{
		if (it1->data.deg == it2->data.deg)
		{
			if ((it1->data.koef + it2->data.koef) != 0)
				result.polinom.Push_Back(*(it1)+*(it2));
			++it1; ++it2;
		}
		else if (it1->data.deg > it2->data.deg)
		{
			result.polinom.Push_Back(*it1);
			++it1;
		}
		else if (it1->data.deg < it2->data.deg)
		{
			result.polinom.Push_Back(*it2);
			++it2;
		}
	}
	while (it2 != side.polinom.End())
	{
		result.polinom.Push_Back(*it2);
		++it2;
	}
	return result;
}

TPolinom TPolinom::operator-(TPolinom & pl)
{
	if (this->polinom.IsEmpty() || pl.polinom.IsEmpty())
		throw "lists is empty, call method Convert";
	TPolinom main, side, result;
	TList<Monom>::iterator it1, it2;
	if (this->polinom.GetSize() >= pl.polinom.GetSize())
	{
		main = *this;
		side = pl;
		it1 = this->polinom.Begin();
		it2 = pl.polinom.Begin();
	}
	else
	{
		main = pl;
		side = *this;
		it1 = pl.polinom.Begin();
		it2 = this->polinom.Begin();
	}
	for (it1; it1 != main.polinom.End();)
	{
		if (it1->data.deg == it2->data.deg)
		{
			if ((it1->data.koef - it2->data.koef) != 0)
				result.polinom.Push_Back(*(it1)-*(it2));
			++it1; ++it2;
		}
		else if (it1->data.deg > it2->data.deg)
		{
			result.polinom.Push_Back(*it1);
			++it1;
		}
		else if (it1->data.deg < it2->data.deg)
		{
			result.polinom.Push_Back(*it2);
			++it2;
		}
	}
	while (it2 != side.polinom.End())
	{
		result.polinom.Push_Back(*it2);
		++it2;
	}
	return result;
}

TPolinom & TPolinom::operator=(const TPolinom & pl)
{
	this->polinom = pl.polinom;
	this->prefix = pl.prefix;
	return *this;
}

bool TPolinom::operator==(const TPolinom & pl)const 
{
	if (this->prefix == pl.prefix)
		return true;
	else return false;
}

ostream & operator<<(ostream & os, TPolinom & pl)
{
	if (pl.polinom.IsEmpty())
		os << pl.prefix;
	else
	{
		for (auto it = pl.polinom.Begin(); it != pl.polinom.End(); ++it)
		{
			if (it != pl.polinom.Begin() &&it->data.koef>0)
				os << '+';
			if(it->data.koef!=1)
				os << it->data.koef;
			os <<it->data.name;
		}
	}
	return os;
}

istream & operator>>(istream & is, TPolinom & pl)
{
	is >> pl.prefix;
	return is;
}

