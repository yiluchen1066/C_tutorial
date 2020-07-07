#include <ctype.h>
/* do-while 循环 在循环体执行后测试终止条件，循环体至少可以被执行一次。 先执行循环体中的语句部分，然后再求表达式的值，如果表达式的值为真，则再执行语句
当表达式的值为假，则循环终止 */ 
/* itoa 函数：将数字n转换为字符串并保存到s中 */ 

void itoa (int n, char s[])
{
    if((sign = n) < 0)
        n = -n; 
    i = 0; 
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse (s);

}