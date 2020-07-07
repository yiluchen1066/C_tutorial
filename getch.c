#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE]; 
int bufp = 0; 

int getch (void) /* 取一个字符 可能是压回的字符 */
{
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}

/* getchar() 函数是直接从输入中读字符 */

void ungetch (int c) /* 把字符压回到输入中 */ 
{
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n"); 
    else
    {
        buf[bufp++] = c; 
    }
    
}