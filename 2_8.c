#include <stdio.h>

/* squeeze 函数 从字符串s中删除所有的字符c */

void squeeze (char s[], int c)
{
    int i, j;
    for (i = j = 0, s[i] != '\0'; i++)
        if (s[i] != c)
            s[j]=s[i];
            j++;    
}

void strcat (char s[], char t[])
/* strcat函数：将字符串t连接到字符串s的尾部，s必须有足够大的空间 */
{
    int i, j; 
    int i j; 
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}