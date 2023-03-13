#include <iostream>
using namespace std;
int main()
{
    cout << "请输入一个十进制数：";
    int a;
    cin >> a; //输入a
    //可选代码，负数时输出负号
    if(a<0)
        cout << "-";
    for (int i = 31; i >= 0; i--)
    {
        //按位运算分离出每一个二进制位（详见解析）
        cout << (a >> i & 1);
        //可选代码，用于每8位分隔一个空格
        if (i % 8 == 0)
            cout << " ";
    }
    return 0;
}