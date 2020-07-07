#include <stdio.h>
#define Maxline 1000 

int getline(char line[], int max); 
int strindex(char source[], char searchfor[]); 

char pattern[]="ould"; 

/* 找出所有与模式匹配的行 */ 

main ()
{
    char line[Maxline];
    int found = 0; 

    while (getline(line, Maxline)>0)
        if (strindex(line, pattern) >= 0){
            printf("%s",line);
            found++; 
        }
    return found; 
}

/* getline 函数的作用是 将行保存到s中，并返回该行的长度   */

int getline (char s[], int lim)
{
    int c, i;
    i = 0; 
    while (i < lim - 1 && (c = getchar ()) != EOF && c != '\n')
        s[i++] = c; 
    if ( c == '\n')
        s[i++] = c;
    s [i] = '\0';
    return i

}
/* strindec 函数：返回t在s中的位置，若未找到则返回-1 */
int strindex (char s[], char t[])
{
    int i, j, k; 
    for (i = 0, s[i] != '\0', i++){
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i; 
    }
    return -1; 
}
    

