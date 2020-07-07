#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100 

/* 用指向结构的指针和结构数组，重新编写关键字统计程序，采用指针，而不使用数组下标*/

int getword(char *, int); 
struct key *binsearch(char *, struct key *, int); /* binsearch 函数在声明中必须表明，它返回的值类型是
一个指向struct key类型的指针，而不是整型。如果binsearch找到与输入单词匹配的数组元素，他将返回一个指向该元素的指针，
否则则返回NULL*/

struct key
{
    char *word; 
    int count; 
};

struct keytab[NKEYS]; 

main()
{
    char word[MAXWORD];
    struct key *p;  /*声明一个指向struct key类型的指针p*/

    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            if ((p = binsearch(word, keytab, NKEYS)) != NULL)
            {
                p -> count++;  /* p -> count++ 等价于 (*p).count++ */
            }
            
        }
        
    }
    for (p = keytab; p < keytab + NKEYS; p++)
    {
        if (p -> count >0)
        {
            printf("%4d %s\n", p -> count, p -> word);
        }
    }

    return 0;
}

/*binsearch 函数*/

/*在这里，low 和high的初值分别是指向表头元素的指针和指向表尾元素后面一个元素的指针，mid设置为指向high和low之间的中间元素的指针
但是两个指针之间的加法运算是非法的，两个指针间的减法运算是合法的*/
struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond; 
    struct key *low = &tab[0]; /*意思是 low, high 和mid都是指向struct key类型的指针*/
    struct key *high = &tab[n]; 
    struct key *mid; 

    while (low < high)
    {
        mid = low + (high - low)/2; 
        if ((cond = strcmp(word, mid -> word)) < 0)
        {
            high = mid; 
        }
        else if (cond >0)
        {
            low = mid +1; 
        }
        else
        {
            return mid;
        }
        
    return NULL; 
    }
    
};



