#include "primejudge.h"

typedef unsigned long long BIG;
// #define DEBUG 
bool IsPrime(BIG input)
{
	BIG i;
	if (input == 2 || input == 3) return 1;
	if (input % 6 != 1 && input % 6 != 5) return 0;

	for (i = 5; i * i <= input; i += 6)
	{
#ifdef DEBUG
        cout << input << ':' << i << endl;
#endif // DEBUG

		if (!(input % i) || !(input%(i + 2))) return 0;
	}
	return 1;
}

void GoldBachInitialize(BIG* input)
{
    clock_t start, end;
    int i = 0;
    start = clock();
    while (true)
    {
        if (!input[i]) break;
        GoldBach(input[i]);
        i++;
    }
    end = clock();

    cout << "\n��ʱ��" << ((double)end - (double)start) / CLOCKS_PER_SEC * 1000.0 << "ms" << endl;

    return;
}

bool GoldBach(BIG input)
{
    if (0 == input) // ����0������˳�
    {
        return 0;
    }
    else if (input % 2) // ����ż����ʾ
    {
        cout << input << "��������������֤" << endl;
    }
    else if (input < 0) // ���븺����ʾ
    {
        cout << input << "�Ǹ�����������֤" << endl;
    }
    else if (input <= 2)
    {
        cout << input << "��С�ڵ���2������������֤" << endl;
    }
    else // �������ż������ʼ�ж�
    {
        int i;
        bool flag = 0;
        if ((flag = IsPrime(input - 2)) || IsPrime(input - 3)) // �ж��Ƿ�����input == 2(3) + Y
        {
#ifdef DEBUG
            cout << 3 - flag << endl;
#endif // DEBUG
            cout << input << '=' << 3 - flag << '+' << input - 3 + flag << endl;
            flag = 1;
        }
             
        for (i = 5; i <= input / 2; i += 6) // i <= input/2, ��֤x<=y
        {
#ifdef DEBUG
            cout << i << endl;
#endif // DEBUG

            if (IsPrime(i) & IsPrime(input - i))
            {
                cout << input << '=' << i << '+' << input - i << endl;
                flag = 1;
            }
            else if (IsPrime((size_t)i + 2) & IsPrime(input - i - 2))
            {
                cout << input << '=' << i + 2 << '+' << input - i - 2 << endl;
                flag = 1;
            }
            if (flag) break;
        }
        if (!flag)
        {
            cout << "��ϲ����ƶ��Ƚ�����" << endl;
        }
    }
    return 0;
}
