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

int TPolinom::Change_Num_System(int a)//возможно тупо ненужная функция 
{
	vector<int>rem;
	int	result = 0;
	int i = 0;
	while (a >= p)
	{
		rem.push_back(a % p);
		a = a / p;
	}
	rem.push_back(a);
	for (int i = 0; i < rem.size(); i++)
		result += pow(10, i)*rem[i];
	return result;
}

int TPolinom::GetDegree(char p)
{
	if (int(p) > 49 && int(p) < 58)
		return int(p - 48);
	else return 1;
}

void TPolinom::Fill_List()
{
	Monom mn;
	string num;
	for (int i = 0; i < str.size(); i++)
	{
		mn = {};
		bool sign = true;
		if (str[i] == '-')
		{
			sign = false;
			i++;
		}
		if (!IsSign(str[i]) && !IsVariable(str[i]))//если не переменная и не знак(считывание коэфициента перед мономом)
		{
			while (!IsVariable(str[i]) && i != str.size() && !IsSign(str[i]))//пока не встретим переменную x y z 
			{
				num += str[i];
				i++;
			}
			mn.koef = atof(num.c_str());
			num = "";
			if (!sign)
				mn.koef = mn.koef*(-1);
		}
		if (IsVariable(str[i]))
		{
			int x = 0, y = 0, z = 0, sum;
			while (!IsSign(str[i]) && i != str.size())
			{
				switch (str[i])
				{
				case 'x':
				{
					x = GetDegree(str[i + 1]);
					i++;
					break;
				}
				case 'y':
				{
					y = GetDegree(str[i + 1]);
					i++;
					break;
				}
				case 'z':
				{
					z = GetDegree(str[i + 1]);
					i++;
					break;
				}
				default:
					i++;
				}
			}
			i--;
			sum = x * 100 + y * 10 + z;
			mn.deg = sum;//Change_Num_System(sum);
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

TPolinom::TPolinom(string _str) :str(_str)
{

}
