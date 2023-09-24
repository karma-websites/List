#include "processFunc.h"

void ignoreLine()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

unsigned getValue(string key = "")
{
    while (true)
    {
        unsigned value;
        cin >> value;
        if ((cin.fail() || value > 20 || value < 1) && key == "sizeListArr")
        {
            cin.clear();
            ignoreLine();
            cerr << "Ошибка ввода: задан невозможный размер массива.\nПопробуйте снова: ";
        }
        else if ((cin.fail() || value > 15 || value < 0) && key == "mode")
        {
            cin.clear();
            ignoreLine();
            cerr << "Ошибка ввода: метода с таким номером нет в списке.\nПопробуйте снова: ";
        }
        else if (cin.fail())
        {
            cin.clear();
            ignoreLine();
            cerr << "Ошибка ввода. Попробуйте снова: ";
        }
        else
        {
            ignoreLine();
            return value;
        }
    }
}

void pushList(List& list, const unsigned sizeList)
{
	for (size_t i = 0; i < sizeList; i++)
	{
		list.push_back(rand() % sizeList);
	}
}

void switchMenu(const unsigned mode, List* listArr, const unsigned index)
{
    unsigned pos = listArr[index].size_list() / 2;
    switch (mode)
    {
    case 1:
        print(listArr[index]);
        break;
    case 2:
        clear(listArr[index]);
        break;
    case 3:
        ins_list_beg(listArr[index], listArr[index]);
        break;
    case 4:
        ins_list_end(listArr[index], listArr[index]);
        break;
    case 5:
        reverse(listArr[index]);
        break;
    case 6:
        reverse_elem(listArr[index], pos, listArr[index].size_list() - 1);
        break;
    case 7:
        erase(listArr[index], pos);
        break;
    case 8:
        get_elem(listArr[index], pos);
        break;
    case 9:
        insert(listArr[index], 12345, pos);
        break;
    case 10:
        replace(listArr[index], 12345, pos);
        break;
    case 11:
        copy(listArr[index]);
        break;
    case 12:
        ins_list_index(listArr[index], listArr[index], pos);
        break;
    case 13:
        search_in(listArr[index]);
        break;
    case 14:
        search_beg(listArr[index]);
        break;
    case 15:
        search_end(listArr[index]);
        break;
    default:
        return;
    }
}

void fillListArr(List* const listArr, const unsigned sizeListArr)
{
    unsigned sizeList{};
    for (size_t i = 0; i < sizeListArr; i++)
    {
        cout << "Введите размер " << i + 1 << " - го списка: ";
        sizeList = getValue();
        pushList(listArr[i], sizeList);
        cout << "Список " << i + 1 << " успешно заполнен." << endl;
    }
}

void delListArr(List* listArr, const unsigned sizeListArr)
{
    for (size_t i = 0; i < sizeListArr; i++)
    {
        listArr[i].clear();
    }
    delete[] listArr;
}

void process()
{
    cout << "Введите желаемое количество списков, не превышающее 20: ";
    unsigned sizeListArr{ getValue("sizeListArr") };
    cout << "\nБудет заполнено случайными числами " << sizeListArr << " списка/ов." << endl;
    List* listArr = new List[sizeListArr];
    
    fillListArr(listArr, sizeListArr);

    cout << left << "\nГруппа 1. T(n) = O(1)\n"
        << setw(19) << "push_front"  << "добавление элемента в начало списка\n"
        << setw(19) << "push_back" << "добавление элемента в конец списка \n"
        << setw(19) << "pop_front" << "удаление первого элемента списка\n"
        << setw(19) << "pop_back" << "удаление последнего элемента списка\n"
        << setw(19) << "empty" << "проверка списка на пустоту\n"
        << setw(19) << "size_list" << "получение размера списка\n"

        "\nГруппа 2. T(n) = O(n)\n"
        << setw(19) << "1. print" << "вывод всего списка (Примечание: список не будет выведен в консоль)\n"
        << setw(19) << "2. clear" << "удаление всех элементов списка\n"
        << setw(19) << "3. ins_list_beg" << "вставка передаваемого (исходного) списка в начало исходного\n"
        << setw(19) << "4. ins_list_end" << "вставка передаваемого (исходного) списка в конец исходного\n"
        << setw(19) << "5. reverse" << "изменение порядка элементов в списке на обратный\n"
        << "Примечание: в следующей функции местами будут меняться центральный и последний элементы каждого списка.\n"
        << setw(19) << "6. reverse_elem" << "обмен двух элементов списка по индексам\n"
        << "Примечание: за индекс для следующих 4 функций по умолчанию принимается середина каждого списка.\n"
        << setw(19) << "7. erase" << "удаление элемента списка по индексу\n"
        << setw(19) << "8. get_elem" << "получение элемента списка по индексу\n"
        << setw(19) << "9. insert" << "добавление элемента в список по индексу\n"
        << setw(19) << "10. replace" << "замена элемента в списке по индексу на передаваемый элемент\n"

        "\nГруппа 3. T(n, m) = O(n + m)\n"
        << "Примечание: в следующей функции исходный список копируется в пустой.\n"
        << setw(19) << "11. copy" << "создание копии списка (копирование исходного списка в пустой список)\n"
        << "Примечание: в следующей функции передаваемый список вставляется в середину исходного.\n"
        << setw(19) << "12. ins_list_index" << "вставка передаваемого (исходного) списка в исходный, начиная с индекса\n"

        "\nГруппа 4. T(n, m) = O(n * m)\n"
        << setw(19) << "13. search_in" << "проверка на содержание другого списка в списке\n"
        << setw(19) << "14. search_beg" << "поиск первого вхождения другого списка в список\n"
        << setw(19) << "15. search_end" << "поиск последнего вхождения другого списка в список" << endl;

    while (true)
    {
        cout << "\nВведите номер метода двусвязного списка\n"
            "для замера времени его выполнения для каждого из списков. \n"
            "Чтобы выйти из программы введите 0. \n"
            "Ожидание ввода: ";
        unsigned mode{ getValue("mode") };
        cout << endl;
        if (mode == 0)
        {
            cout << "Завершение работы программы." << endl;
            delListArr(listArr, sizeListArr);
            cout << "Все списки успешно удалены." << endl;
            return;
        }
        for (size_t i = 0; i < sizeListArr; i++)
        {
            cout << "Список " << i + 1 << " ";
            switchMenu(mode, listArr, i);
        }
        if (mode == 2)
        {
            cout << "\nТребуется заполнить списки заново\n"
                "Будет заполнено случайными числами " << sizeListArr << " списка/ов." << endl;
            fillListArr(listArr, sizeListArr);
        }
    }
}
