#pragma once
#include "List.h"
#include <chrono>
using namespace std::chrono;

void print(List& list);
void clear(List& list);
void reverse(List& list);
void copy(List& list);
void ins_list_beg(List& listBig, List& listSm);
void ins_list_end(List& listBig, List& listSm);
void ins_list_index(List& listBig, List& listSm, const int index);
void reverse_elem(List& list, const int indexFirst, const int indexSecond);
void search_in(List& listBig);
void search_beg(List& listBig);
void search_end(List& listBig);
void erase(List& list, const int index);
void get_elem(List& list, const int index);
void insert(List& list, const int data, const int indexSecond);
void replace(List& list, const int data, const int indexSecond);