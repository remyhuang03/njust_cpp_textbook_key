#include <cstdio>
int main()
{
    printf("请输入一个十进制数：");
    int a;
    scanf("%d", &a);
    //可选代码，负数时输出负号
    if (a < 0)
        printf("-");
    //直接格式化输出，缺点是没有空格分割不太易读
    printf("%032X", a);
    return 0;
}