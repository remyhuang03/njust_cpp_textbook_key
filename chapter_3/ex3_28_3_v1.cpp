#include <iostream>
using namespace std;
int main()
{
    cout << "请输入一个浮点数：";
    double a;
    cin >> a;         //输入a
    int b = (int)a;   //计算a的整数部分
    double c = a - b; //计算a的小数部分
    cout << b << endl;
    cout << c << endl;
    return 0;
}