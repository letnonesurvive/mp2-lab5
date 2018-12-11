#include <iostream>
#include <string>

const int MAXSIZE = 1000; 
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
		/*Node (const Node<type> &nd)
		{
			pNext = new Node<type>;
			pNext = nd.pNext;
			data = nd.data;
		}*/
		/*Node<type>& operator = (const Node<type> *nd)
		{
			this = new Node<type>;
			this->pNext = nd.pNext;
			this->data = nd.data;
			return *this;
		} */
		bool operator==(const Node<type> &nd)const
		{
			if (this == nd)
				return true;
			else return false;
		}
		bool operator != (const Node<type> &nd) const
		{
			return !(*this == nd);
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
	class iterator
	{
	private:
		Node<type> *pointer;
	public:
		iterator()
		{
			pointer = new Node<type>;
		}
		iterator(const iterator &it)
		{
			pointer = it.pointer;
		}
		Node<type>* base() const 
		{ 
			return pointer;
		}
		iterator& operator=(const iterator &tmp)
		{
			pointer = tmp.pointer;
			return *this;
		}
		Node<type>* operator->() const
		{
			return pointer;
		}
		bool operator == (const iterator &it) const
		{
			if(pointer==it.pointer)
				return true;
			else return false;
		}
		bool operator != (const iterator &it) const
		{
			return !(*this == it);
		}
		const Node<type> operator*()const
		{
			if (pointer == nullptr)
				throw("nullptr");
			return *pointer;
		}
		iterator& operator ++()
		{
			this->pointer = this->pointer->pNext;
			return *this;
		}
		friend class TList;
		//friend class TPolinom;
	};
	TList()
	{
		pFirst = nullptr;
		pCurrent = nullptr;
		pPrevios = nullptr;
		datacount = 0;
	}
	TList(const TList<type> &lst)
	{
		this->pFirst = nullptr;
		this->datacount = 0;
		Node<type>*count = lst.pFirst;
		while (count != nullptr)
		{
			this->Push_Back(count->data);
			count = count->pNext;
		}
	}
	TList<type>& operator = (const TList<type> &lst)
	{
		Node<type>*count=lst.pFirst;
		if(!this->IsEmpty())
			this->Clear();
		while (count != nullptr)
		{
			this->Push_Back(count->data);
			count = count->pNext;
		}
		return *this;
	}
	void Push_Back(type tmp)
	{
		if (IsEmpty())
		{
			pFirst=new Node<type>(tmp);
			pCurrent = pFirst;
			datacount++;
		}
		else
		{
			if (datacount == MAXSIZE)
				throw("Превышено максимальная длина списка");
			pCurrent->pNext = new Node<type>(tmp);
			pPrevios = pCurrent;
			pCurrent = pCurrent->pNext;
			datacount++;
		}
	}
	void Pop_Front()
	{
		Node<type> *tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		datacount--;
	}
	void Insert(iterator it, type val)//вставка по значению и итератору ЧУШЬ!!!
	{
		Node<type> *count = pFirst;
		Node <type> *prev;
		Node<type> *insert = new Node<type>(val);
		int pos = 0;
		while (count != it.pointer)
		{
			prev = count;
			count = count->pNext;
			pos++;
		}
		if (pos == 0)
		{
			Node<type> *tmp = pFirst;
			insert->pNext = tmp;
			pFirst = insert;
			datacount++;
		}
		else
		{
			insert->pNext = count;
			prev->pNext = insert;
			datacount++;
		}
	}
	void Erase(iterator it)
	{
		Node<type> *count = pFirst;
		Node <type> *prev = pPrevios;
		int pos = 0;
		while (count != it.pointer)
		{
			prev = count;
			count = count->pNext;
			pos++;
		}
		if (pos == 0)
		{
			Node<type> *tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
			datacount--;
		}
		else
		{
			prev->pNext = count->pNext;
			delete count;
			datacount--;
		}
	}
	void Clear()
	{
		while (datacount != 0)
			Pop_Front();
	}
	iterator Begin()
	{
		iterator it;
		it.pointer = pFirst;
		return it;
	}
	iterator End()
	{
		iterator it;
		it.pointer = pCurrent->pNext;
		return it;
	}
	int GetSize()
	{
		return datacount;
	}
	bool IsEmpty()
	{
		if (pFirst==nullptr)
			return true;
		else return false;
	}
	friend ostream &operator<<(ostream &os,TList &lst)
	{
		iterator it;
		for (it = lst.Begin(); it != lst.End(); ++it)
			os << *(it) << endl;
		return os;
	}
	~TList()
	{
		Clear();
	}
	friend class iterator;
	//friend class TPolinom;
};
