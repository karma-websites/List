#include "timeFunc.h"

/* 1 */
void print(List& list)
{
	auto begin = steady_clock::now();
	list.print();
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод print выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
}

/* 2 */
void clear(List& list)
{
	auto begin = steady_clock::now();
	list.clear();
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод clear выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
}

/* 3 */
void reverse(List& list)
{
	auto begin = steady_clock::now();
	list.reverse();
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод reverse выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
}

/* 4 */
void copy(List& list)
{
	List* emptyList = new List();
	auto begin = steady_clock::now();
	emptyList->copy(list);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод copy выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
	emptyList->clear();
}

/* 5 */
void ins_list_beg(List& listBig, List& listSm)
{
	auto begin = steady_clock::now();
	listBig.ins_list_beg(listSm);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод ins_list_beg выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
}

/* 6 */
void ins_list_end(List& listBig, List& listSm)
{
	auto begin = steady_clock::now();
	listBig.ins_list_end(listSm);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод ins_list_end выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
}

/* 7 */
void ins_list_index(List& listBig, List& listSm, const int index)
{
	auto begin = steady_clock::now();
	listBig.ins_list_index(listSm, index);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод ins_list_index выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
}

/* 8 */
void reverse_elem(List& list, const int indexFirst, const int indexSecond)
{
	auto begin = steady_clock::now();
	list.reverse_elem(indexFirst, indexSecond);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод reverse_elem выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
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
	cout << "Индекс элемента: " << listBig.search_in(*listSm) << " ";
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод search_in выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
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
	cout << "Индекс элемента: " << listBig.search_beg(*listSm) << " ";
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод search_beg выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
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
	cout << "Индекс элемента: " << listBig.search_end(*listSm) << " ";
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод search_end выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
	listSm->clear();
}

/* 12 */
void erase(List& list, const int index)
{
	auto begin = steady_clock::now();
	list.erase(index);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод erase выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
}

/* 13 */
void get_elem(List& list, const int index)
{
	auto begin = steady_clock::now();
	list.get_elem(index);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод get_elem выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
}

/* 14 */
void insert(List& list, const int data, const int indexSecond)
{
	auto begin = steady_clock::now();
	list.insert(data, indexSecond);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод insert выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
}

/* 15 */
void replace(List& list, const int data, const int indexSecond)
{
	auto begin = steady_clock::now();
	list.replace(data, indexSecond);
	auto end = steady_clock::now();
	auto elapsed_ns = duration_cast<nanoseconds>(end - begin);
	cout << "Метод replace выполнился за " << elapsed_ns.count() << " нс = " << elapsed_ns.count() * 0.000001 << " мс" << endl;
}