#include <iostream>
#include "primejudge.h"
#include <cmath>
#include <fstream>
#include <cstdio>
#include "bonus.h"

using namespace std;

typedef unsigned long long BIG;

/* define the max volume of the arry */
const int MAX_ARRAY = 1000;

bool InputCheck()
{
    if (cin.fail()) // Input error handling
    {
        cin.clear(), cin.sync();
        while (cin.get() != '\n'); // Clear this line
        return false;
    }
    else
        return true;
}

int main(void)
{
    //PrimeSieve(10000000);
    BIG input[MAX_ARRAY];
    int i = 0, mode = 0;
    // welcome
    cout << "**************GOLD BACH CONJECTURE**************\n" << endl;

    // sample
    cout << "��sample input��:" << endl;
    for (int x = 0, y = 1; x < 5; x++) cout << (y = y * 10) << endl;
    cout << "��sample output��:" << endl;
    for (int x = 0, y = 1; x < 5; x++) GoldBach((BIG)(y *= 10));
    cout << endl;

    cout << "���������4��ż�����У����ڽ�β����0��ʾ�˳���" << endl;
    while (true)
    {
        cin >> input[i];
        if (!InputCheck())
        {
            cout << "��������unsigned long long����������("
                << 4 << '~' << (BIG)0 - 2 << ')' << endl;
            continue;
        }
        if (input[i] == 0)  break;
        i++;
    }

    // menu
    cout << "ģʽ1��ֱ�����㡣\n" << "ģʽ2����ʼ�����������㡣\n" << "������ѡ��";
    while (true) {
        cin >> mode;
        if (!InputCheck()) cout << "��������ţ�(1~2)" << endl;
        else break;
    }

    switch (mode)
    {
    case 1:GoldBachInitialize(input);
        break;
    case 2:GoldBachBonus(input);
        break;
    default:
        break;
    }

    return 0;
}
