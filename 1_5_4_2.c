#include <stdio.h>
/* 编写一个程序，以每一行一个单词的形式打印其输入 */ 
int main ()
{
    int c, count; 
    count = 0; 
    while ( (c = getchar ()) != EOF){
        if (c != " "){
            putchar(c);
        if (c == ""){
            putchar('\n');
        }
        }
    }
}

int main ()
{
    int c, count; 
    count = 0; 
    while ( (c = getchar ()) != EOF){
        if (c != ' '){
            count = 0; 
            putchar (c);
        }
        else if (count == 0)
        {
            putchar (c); 
            count = count +1 ; 
        if (c == ' ')
            putchar('\n');
        }
    }
    return 0;
}