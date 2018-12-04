#include <iostream>
#include <string>

const int MAXSIZE = 100; 
using namespace std;

template <class type>
class TList
{
private:
	template <class type>
	struct Node
	{
		Node *pNext;
		type data;
		Node(type _data = {}, Node *_pNext = nullptr)
		{
			pNext = _pNext;
			data = _data;
		}
		friend ostream &operator<<(ostream &os, Node<type> nd)
		{
			os << nd.data;
			return os;
		}
	};
	int datacount;//кол-во элементов в списке
	Node <type> *pFirst;//заголовок
	Node <type> *pCurrent;//указатель на текущий 
	Node <type> *pPrevios;//указатель на предыдущий
 public:
	class iter//осталось инкрементировать итератор.
	{
		Node<type> *pointer;
	public:
		iter()
		{
			pointer = new Node<type>;
		}
		iter & operator=(const Node<type> &tmp)
		{
			this->pointer->data = tmp.data;
			this->pointer->pNext = tmp.pNext;
			return *this;
		}
		friend ostream &operator<<(ostream &os,iter &it)
		{
			os << it.pointer;
			return os;
		}
		const Node<type> operator*()const
		{
			return *pointer;
		}
	};
	TList()
	{
		pFirst = nullptr;
		pCurrent = nullptr;
		pPrevios = nullptr;
		datacount = 0;
	}
	void Push_Back(type tmp)
	{
		if (IsEmpty())
		{
			pFirst = new Node<type>(tmp);
			pCurrent = pFirst;
			datacount++;
		}
		else
		{
			pCurrent->pNext = new Node<type>(tmp);
			pPrevios = pCurrent;
			pCurrent = pCurrent->pNext;
			datacount++;
		}
	}
	Node<type> Begin()
	{
		return *pFirst;
	}
	int GetSize()
	{
		return datacount;
	}
	bool IsEmpty()
	{
		if (pFirst == nullptr)
			return true;
		else return false;
	}
	friend ostream &operator<<(ostream &os,TList &lst)
	{
		Node<type> *i = lst.pFirst;
		while (i != nullptr)
		{
			os << i->data << endl;
			i = i->pNext;
		}
		return os;
	}
};
