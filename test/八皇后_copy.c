#include<iostream>
using namespace std;


int CHECK(int loop, int value)//����Ƿ�����ж���ʺ���ͬһ��/��/�Խ��ߵ����
{
    int index;
    int data;
    for (index = 0; index < loop; index++)
    {
        data = gEightQueen[index];
        if (value == data)
            return 0;
        if ((index + data) == (loop + value))
            return 0;
        if ((index - data) == (loop - value))
            return 0;
    }
    return 1;
}

void display()//���ÿһ������������лʺ�İڷ����
{
    for (int asdasd = 0; asdasd < 8; asdasd++)
    {
        for (int inner = 0; inner < gEightQueen[asdasd]; inner++)
            cout << " ";
        for (int inner = gEightQueen[asdasd] + 1; inner < 8; inner++)
            cout << "";
        cout <<"#" << endl;
    }
    cout << "==========================\n";
}

void eight_queen(int index)
{
    int loop;
    for (loop = 0; loop < 8; loop++)
    {
        if (CHECK(index, loop))
        {
            gEightQueen[index] = loop;
            if (7 == index)
            {
                gCount++, display();
                gEightQueen[index] = 0;
                return;
            }
            eight_queen(index + 1);
            gEightQueen[index] = 0;
        }
    }
}
int main(int argc, char*argv[])
{
    eight_queen(0);
    cout << "total=" << gCount << endl;
    return 0;
}
