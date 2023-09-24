#pragma once
#include <iostream>

using namespace std;

class List
{
	struct Node
	{
		int data;
		Node* pNext, * pPrev;

		Node(int data, Node* pPrev = nullptr, Node* pNext = nullptr)
		{
			this->data = data;
			this->pPrev = pPrev;
			this->pNext = pNext;
		}
	};
	int size;
	Node* pHead, * pCur, * pTail;

	Node* move(const int index);
	void swap(Node* const pFirst, Node* const pSecond);
	bool correct_index(const int index);

public:
	List();
	List(const List& obj);
	~List();

	/* ������ 1 */
	void push_front(const int data);	// ���������� �������� � ������ ������ 
	void push_back(const int data);	// ���������� �������� � ����� ������ 
	void pop_front();	// �������� ������� �������� ������
	void pop_back();	// �������� ���������� �������� ������
	bool empty() const;	// �������� ������ �� �������
	int size_list() const { return size; } // ��������� ������� ������

	/* ������ 2 */
	void print(string msg);	// ����� ����� ������
	void clear();	// �������� ���� ��������� ������

	void copy(const List& obj);	// �������� ����� ������
	void reverse();	// ��������� ������� ��������� � ������ �� ��������
	void ins_list_beg(const List& list);	// ������� ������������� ������ � ������ ���������
	void ins_list_end(const List& list);	// ������� ������������� ������ � ����� ���������

	/* ������ 3 */
	void ins_list_index(const List& list, const int index);	// ������� ������������� ������ � ��������, ������� � �������

	/* ������ 4 */
	void reverse_elem(const int firstIndex, const int secondIndex);	// ����� ���� ��������� ������ �� ��������

	/* ������ 5 */
	bool search_in(List& list);	// �������� �� ���������� ������� ������ � ������
	int search_beg(List& list);	// ����� ������� ��������� ������� ������ � ������ 
	int search_end(List& list);	// ����� ���������� ��������� ������� ������ � ������

	/* ������ 6 */
	void erase(const int index);	// �������� �������� ������ �� ������� 
	int get_elem(const int index);	// ��������� �������� ������ �� �������
	void insert(const int data, const int index);	// ���������� �������� � ������ �� �������
	void replace(const int data, const int index);	// ������ �������� � ������ �� ������� �� ������������ �������
};

inline List::List() : pHead{ nullptr }, pCur{ nullptr }, pTail{ nullptr }, size{0} {}

inline List::List(const List& obj)
{
	this->copy(obj);
}

inline List::~List() { clear(); }

inline void List::push_front(const int data)
{
	pCur = new Node(data);
	if (!pHead)
		pTail = pCur;
	else
	{
		pCur->pNext = pHead;
		pHead->pPrev = pCur;
	}
	pHead = pCur;
	size++;
}

inline void List::push_back(const int data)
{
	pCur = new Node(data);
	if (!pHead)
		pHead = pCur;
	else
	{
		pCur->pPrev = pTail;
		pTail->pNext = pCur;
	}
	pTail = pCur;
	size++;
}

inline void List::pop_front()
{
	if (!empty())
	{
		Node* temp = pHead;
		if (pHead->pNext)
		{
			pHead = pHead->pNext;
			pHead->pPrev = nullptr;
		}
		else pHead = pCur = pTail = nullptr;
		delete temp;
		size--;
	}
}

inline void List::pop_back()
{
	if (!empty())
	{
		Node* temp = pTail;
		if (pTail->pPrev)
		{
			pTail = pTail->pPrev;
			pTail->pNext = nullptr;
		}
		else pHead = pCur = pTail = nullptr;
		delete temp;
		size--;
	}
}

inline void List::erase(const int index)
{
	Node* temp = move(index);
	if (temp->pPrev && temp->pNext)
	{
		temp->pPrev->pNext = temp->pNext;
		temp->pNext->pPrev = temp->pPrev;
	}
	else if (temp->pPrev && !temp->pNext)
	{
		temp->pPrev->pNext = nullptr;
		pTail = temp->pPrev;
	}
	else if (!temp->pPrev && temp->pNext)
	{
		temp->pNext->pPrev = nullptr;
		pHead = temp->pNext;
	}
	delete temp;
	size--;
}

inline bool List::empty() const
{
	if (pHead && pTail)
		return false;
	return true;

}

inline void List::copy(const List& obj)
{
	this->clear();
	Node* temp = obj.pHead;
	while (temp)
	{
		this->push_back(temp->data);
		temp = temp->pNext;
	}
}

inline List::Node* List::move(const int index)
{
	if (correct_index(index))
	{
		pCur = pHead;
		for (size_t i = 0; i < index; i++)
		{
			pCur = pCur->pNext;
		}
		return pCur;
	}
	else
	{
		cout << "������: �������� � �������� " << index << " ��� � ������.\n";
		exit(0);
	}
}

inline void List::swap(Node* const pFirst, Node* const pSecond)
{
	int temp = pSecond->data;
	pSecond->data = pFirst->data;
	pFirst->data = temp;
}

inline int List::get_elem(const int index)
{
	return move(index)->data;
}

inline bool List::correct_index(const int index)
{
	return (index >= 0) && (index < size);
}

inline void List::print(string msg = "")
{
	cout << msg << " => ";
	pCur = pHead;
	while (pCur)
	{
		//cout << pCur->data << " ";
		pCur = pCur->pNext;
	}
	//cout << endl;
}

inline void List::insert(const int data, const int index)
{
	pCur = move(index);
	Node* elem = new Node(data, pCur->pPrev, pCur);
	if (pCur->pPrev)
		pCur->pPrev->pNext = elem;
	else pHead = elem;
	pCur->pPrev = elem;
	size++;
}

inline void List::ins_list_beg(const List& list)
{
	if (!list.empty() && !this->empty())
	{
		List* obj = new List();
		obj->copy(list);
		this->pHead->pPrev = obj->pTail;
		obj->pTail->pNext = this->pHead;
		this->pHead = obj->pHead;
		size += obj->size;
	}
}

inline void List::ins_list_end(const List& list)
{
	if (!list.empty() && !this->empty())
	{
		List* obj = new List();
		obj->copy(list);
		this->pTail->pNext = obj->pHead;
		obj->pHead->pPrev = this->pTail;
		this->pTail = obj->pTail;
		size += obj->size;
	}
}

inline void List::ins_list_index(const List& list, const int index)
{
	if (index == this->size_list() - 1)
	{
		this->ins_list_end(list);
	}
	else
	{
		pCur = move(index);
		List* obj = new List();
		obj->copy(list);
		obj->pTail->pNext = this->pCur->pNext;
		this->pCur->pNext->pPrev = obj->pTail;
		this->pCur->pNext = obj->pHead;
		obj->pHead->pPrev = this->pCur;
	}
}

inline void List::replace(const int data, const int index)
{
	pCur = move(index);
	pCur->data = data;
}

inline void List::reverse_elem(const int firstIndex, const int secondIndex)
{
	swap(move(firstIndex), move(secondIndex));
}

inline void List::reverse()
{
	Node* it1 = pHead, * it2 = pTail;
	while (it1 != it2)
	{
		swap(it1, it2);
		if (it1->pNext == it2)
			break;
		it1 = it1->pNext;
		it2 = it2->pPrev;
	}
}

inline bool List::search_in(List& list)
{
	if (list.empty() || this->empty())
	{
		cout << "������ 1 ��� ������ 2 �� �������� ���������.\n";
		return false;
	}
	else if (list.size_list() > this->size_list())
	{
		cout << "������ 2 ������ ������ 1.\n";
		return false;
	}

	List* obj = new List();
	obj->copy(list);

	this->pCur = this->pHead;
	obj->pCur = obj->pHead;

	int count = 0;
	while (pCur)
	{
		Node* temp = this->pCur;
		if (this->pCur->data == obj->pCur->data)
		{
			while (obj->pCur && this->pCur)
			{
				if (obj->pCur->data != this->pCur->data)
					break;
				else
				{
					obj->pCur = obj->pCur->pNext;
					this->pCur = this->pCur->pNext;
					count++;
				}
			}
			if (count == obj->size_list())
			{
				obj->clear();
				return true;
			}
			else
			{
				count = 0;
				this->pCur = temp;
				obj->pCur = obj->pHead;
			}
			if (!this->pCur)
			{
				obj->clear();
				return false;
			}
		}
		this->pCur = this->pCur->pNext;
	}
	obj->clear();
	return false;
}

inline int List::search_beg(List& list)
{
	if (list.empty() || this->empty())
	{
		cout << "������ 1 ��� ������ 2 �� �������� ���������.\n";
		return -1;
	}
	else if (list.size_list() > this->size_list())
	{
		cout << "������ 2 ������ ������ 1.\n";
		return -1;
	}

	List* obj = new List();
	obj->copy(list);

	this->pCur = this->pHead;
	obj->pCur = obj->pHead;

	int count = 0, index = 0;
	while (pCur)
	{
		Node* temp = this->pCur;
		if (this->pCur->data == obj->pCur->data)
		{
			while (obj->pCur && this->pCur)
			{
				if (obj->pCur->data != this->pCur->data)
					break;
				else
				{
					obj->pCur = obj->pCur->pNext;
					this->pCur = this->pCur->pNext;
					count++;
				}
			}
			if (count == obj->size_list())
			{
				obj->clear();
				return index;
			}
			else
			{
				count = 0;
				this->pCur = temp;
				obj->pCur = obj->pHead;
			}
			if (!this->pCur)
			{
				obj->clear();
				return -1;
			}
		}
		index++;
		this->pCur = this->pCur->pNext;
	}
	obj->clear();
	return -1;
}

inline int List::search_end(List& list)
{
	if (list.empty() || this->empty())
	{
		cout << "������ 1 ��� ������ 2 �� �������� ���������.\n";
		return -1;
	}
	else if (list.size_list() > this->size_list())
	{
		cout << "������ 2 ������ ������ 1.\n";
		return -1;
	}

	List* obj = new List();
	obj->copy(list);

	this->pCur = this->pTail;
	obj->pCur = obj->pTail;

	int count = 0, index = 0;
	while (pCur)
	{
		Node* temp = this->pCur;
		if (this->pCur->data == obj->pCur->data)
		{
			while (obj->pCur && this->pCur)
			{
				if (obj->pCur->data != this->pCur->data)
					break;
				else
				{
					obj->pCur = obj->pCur->pPrev;
					this->pCur = this->pCur->pPrev;
					count++;
				}
			}
			if (count == obj->size_list())
			{
				obj->clear();
				return this->size_list() - obj->size_list() - index;
			}
			else
			{
				count = 0;
				this->pCur = temp;
				obj->pCur = obj->pTail;
			}
			if (!this->pCur)
			{
				obj->clear();
				return -1;
			}
		}
		index++;
		this->pCur = this->pCur->pPrev;
	}
	obj->clear();
	return -1;
}

inline void List::clear()
{
	while (size)
		pop_back();
}
