#include "timeFunc.h"

/* 1 */
void print(List& list)
{
	auto begin = steady_clock::now();
	list.print();
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� print ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}

/* 2 */
void clear(List& list)
{
	auto begin = steady_clock::now();
	list.clear();
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� clear ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}

/* 3 */
void reverse(List& list)
{
	auto begin = steady_clock::now();
	list.reverse();
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� reverse ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}

/* 4 */
void copy(List& list)
{
	List* emptyList = new List();
	auto begin = steady_clock::now();
	emptyList->copy(list);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� copy ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
	emptyList->clear();
}

/* 5 */
void ins_list_beg(List& listBig, List& listSm)
{
	auto begin = steady_clock::now();
	listBig.ins_list_beg(listSm);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� ins_list_beg ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}

/* 6 */
void ins_list_end(List& listBig, List& listSm)
{
	auto begin = steady_clock::now();
	listBig.ins_list_end(listSm);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� ins_list_end ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}

/* 7 */
void ins_list_index(List& listBig, List& listSm, const int index)
{
	auto begin = steady_clock::now();
	listBig.ins_list_index(listSm, index);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� ins_list_index ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}

/* 8 */
void reverse_elem(List& list, const int indexFirst, const int indexSecond)
{
	auto begin = steady_clock::now();
	list.reverse_elem(indexFirst, indexSecond);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� reverse_elem ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}

/* 9 */
void search_in(List& listBig)
{
	List* listSm = new List();
	for (size_t i = 0; i < listBig.size_list() / 2; i++)
	{
		listSm->push_back(rand() % (listBig.size_list() / 2));
	}
	auto begin = steady_clock::now();
	cout << "������ ��������: " << listBig.search_in(*listSm) << " ";
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� search_in ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
	listSm->clear();
}

/* 10 */
void search_beg(List& listBig)
{
	List* listSm = new List();
	for (size_t i = 0; i < listBig.size_list() / 2; i++)
	{
		listSm->push_back(rand() % (listBig.size_list() / 2));
	}
	auto begin = steady_clock::now();
	cout << "������ ��������: " << listBig.search_beg(*listSm) << " ";
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� search_beg ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
	listSm->clear();
}

/* 11 */
void search_end(List& listBig)
{
	List* listSm = new List();
	for (size_t i = 0; i < listBig.size_list() / 2; i++)
	{
		listSm->push_back(rand() % (listBig.size_list() / 2));
	}
	auto begin = steady_clock::now();
	cout << "������ ��������: " << listBig.search_end(*listSm) << " ";
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� search_end ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
	listSm->clear();
}

/* 12 */
void erase(List& list, const int index)
{
	auto begin = steady_clock::now();
	list.erase(index);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� erase ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}

/* 13 */
void get_elem(List& list, const int index)
{
	auto begin = steady_clock::now();
	list.get_elem(index);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� get_elem ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}

/* 14 */
void insert(List& list, const int data, const int indexSecond)
{
	auto begin = steady_clock::now();
	list.insert(data, indexSecond);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� insert ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}

/* 15 */
void replace(List& list, const int data, const int indexSecond)
{
	auto begin = steady_clock::now();
	list.replace(data, indexSecond);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "����� replace ���������� �� " << elapsed_ns.count() << " �� = " << elapsed_ns.count() * 0.000001 << " ��" << endl;
}