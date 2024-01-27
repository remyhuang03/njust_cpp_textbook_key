#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    //注意两整型做除法不能得到算术意义上的正确结果，
    //要进行类型转换
    cout << "a / b = " << double(a) / b << endl;
}