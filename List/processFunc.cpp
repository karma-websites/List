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
            cerr << "������ �����: ����� ����������� ������ �������.\n���������� �����: ";
        }
        else if ((cin.fail() || value > 15 || value < 0) && key == "mode")
        {
            cin.clear();
            ignoreLine();
            cerr << "������ �����: ������ � ����� ������� ��� � ������.\n���������� �����: ";
        }
        else if (cin.fail())
        {
            cin.clear();
            ignoreLine();
            cerr << "������ �����. ���������� �����: ";
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
        cout << "������� ������ " << i + 1 << " - �� ������: ";
        sizeList = getValue();
        pushList(listArr[i], sizeList);
        cout << "������ " << i + 1 << " ������� ��������." << endl;
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
    cout << "������� �������� ���������� �������, �� ����������� 20: ";
    unsigned sizeListArr{ getValue("sizeListArr") };
    cout << "\n����� ��������� ���������� ������� " << sizeListArr << " ������/��." << endl;
    List* listArr = new List[sizeListArr];
    
    fillListArr(listArr, sizeListArr);

    cout << left << "\n������ 1. T(n) = O(1)\n"
        << setw(19) << "push_front"  << "���������� �������� � ������ ������\n"
        << setw(19) << "push_back" << "���������� �������� � ����� ������ \n"
        << setw(19) << "pop_front" << "�������� ������� �������� ������\n"
        << setw(19) << "pop_back" << "�������� ���������� �������� ������\n"
        << setw(19) << "empty" << "�������� ������ �� �������\n"
        << setw(19) << "size_list" << "��������� ������� ������\n"

        "\n������ 2. T(n) = O(n)\n"
        << setw(19) << "1. print" << "����� ����� ������ (����������: ������ �� ����� ������� � �������)\n"
        << setw(19) << "2. clear" << "�������� ���� ��������� ������\n"
        << setw(19) << "3. ins_list_beg" << "������� ������������� (���������) ������ � ������ ���������\n"
        << setw(19) << "4. ins_list_end" << "������� ������������� (���������) ������ � ����� ���������\n"
        << setw(19) << "5. reverse" << "��������� ������� ��������� � ������ �� ��������\n"
        << "����������: � ��������� ������� ������� ����� �������� ����������� � ��������� �������� ������� ������.\n"
        << setw(19) << "6. reverse_elem" << "����� ���� ��������� ������ �� ��������\n"
        << "����������: �� ������ ��� ��������� 4 ������� �� ��������� ����������� �������� ������� ������.\n"
        << setw(19) << "7. erase" << "�������� �������� ������ �� �������\n"
        << setw(19) << "8. get_elem" << "��������� �������� ������ �� �������\n"
        << setw(19) << "9. insert" << "���������� �������� � ������ �� �������\n"
        << setw(19) << "10. replace" << "������ �������� � ������ �� ������� �� ������������ �������\n"

        "\n������ 3. T(n, m) = O(n + m)\n"
        << "����������: � ��������� ������� �������� ������ ���������� � ������.\n"
        << setw(19) << "11. copy" << "�������� ����� ������ (����������� ��������� ������ � ������ ������)\n"
        << "����������: � ��������� ������� ������������ ������ ����������� � �������� ���������.\n"
        << setw(19) << "12. ins_list_index" << "������� ������������� (���������) ������ � ��������, ������� � �������\n"

        "\n������ 4. T(n, m) = O(n * m)\n"
        << setw(19) << "13. search_in" << "�������� �� ���������� ������� ������ � ������\n"
        << setw(19) << "14. search_beg" << "����� ������� ��������� ������� ������ � ������\n"
        << setw(19) << "15. search_end" << "����� ���������� ��������� ������� ������ � ������" << endl;

    while (true)
    {
        cout << "\n������� ����� ������ ����������� ������\n"
            "��� ������ ������� ��� ���������� ��� ������� �� �������. \n"
            "����� ����� �� ��������� ������� 0. \n"
            "�������� �����: ";
        unsigned mode{ getValue("mode") };
        cout << endl;
        if (mode == 0)
        {
            cout << "���������� ������ ���������." << endl;
            delListArr(listArr, sizeListArr);
            cout << "��� ������ ������� �������." << endl;
            return;
        }
        for (size_t i = 0; i < sizeListArr; i++)
        {
            cout << "������ " << i + 1 << " ";
            switchMenu(mode, listArr, i);
        }
        if (mode == 2)
        {
            cout << "\n��������� ��������� ������ ������\n"
                "����� ��������� ���������� ������� " << sizeListArr << " ������/��." << endl;
            fillListArr(listArr, sizeListArr);
        }
    }
}
