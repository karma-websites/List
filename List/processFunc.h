#pragma once
#include <limits>
#include "timeFunc.h"
#include <iomanip>

void pushList(List& list, const unsigned sizeList);
void switchMenu(const unsigned mode, List* listArr, const unsigned index);
void fillListArr(List* const listArr, const unsigned sizeListArr);
void delListArr(List* listArr, const unsigned sizeListArr);
void process();