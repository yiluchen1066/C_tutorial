#include <ctype.h>

/* atoi 函数： 将字符串s转换为整型数 比如 atoi("1234") 会返回整形1234 */ 

int atoi_1 (char s[])
{
    int i, n, sign; 
    for (i=0,isspace(s[i]); i++)
        ; /*  */
    sign = (s[i] == '-') ? -1: 1; 
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign *n
}

int atoi_2 (char s[])
{
    int i, n, 
    n = 0;
    for (i=0; s[i] >= '0' && s[i] <= '9', i++)
        n = 10 * n + (s[i] - '0')
    return n 
}

