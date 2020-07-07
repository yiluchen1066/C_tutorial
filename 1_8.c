#include <stdio.h>
/* 
读入一组文本行，并把最长的文本行打印出来
程序很自然的分成了若干片段，分别读入新行，测试读入的行，保存新行，其余部分则控制这一过程
*/
# define Maxline 1000
int getline (char line[], int maxline);
void copy (char to [], char from []);

main() 
{
    int len; /* current line length */ 
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */ 

    max = 0;
    while ((len = getline (line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy (longest, line);
        }
    if (max > 0) {
        printf("%s", longest) 
    }
    return 0;
}

int getline(char s[], int lim) /* 读入新的一行 */ 
{
    int c, i;
    for (i=0, i < lim -1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy (char to[], char from[]) /* 保存新行 */ 
{
    int i; 
    i = 0; 
    while ((to[i] = from[i] != '\0'))
        ++i; 
}