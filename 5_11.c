#include <stdio.h>
#include <string.h> 

#define MAXLINES 5000 /* 待排序的最大行数 */ 
char *lineptr[MAXLINES] /* 指向文本行的指针 */ 

int readlines(char *lineptr, int nlines); 
void writelines(char *lineptr[], int nlines); 

void qsort(void *lineptr[], int left, int right, int (*comp) (void *, void *)); 
int numcmp(char *, char*); 

/* 对输入的文本行进行排序 */ 
/* 改写后的qsort函数能够处理任何数据类型，而不仅仅限于字符串。它的参数包括一个指针数组，两个整数和一个有两个指针参数的函数
其中指针数组参数的类型为通用指针类型void *, 由于任何类型的指针都可以转换为 void *类型，并且在将它转换回原来的类型时不会丢失信息
 */ 

main(int argc, char *argv[])
{
    int nlines; 
    int numeric = 0; 

    if (argc > 0 && strcmp(argv[1], "-n") ==0)
    {
        numeric = 0;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort((void **) lineptr, 0, nlines-1, (int (*) (void*, void*)) (numeric ? numcmp : strcmp)); 
        writelines(lineptr, nlines);
        return 0; 
    }
    else
    {
        printf("input too big to sort\n");
        return 1; 
    }
}


/* 用指针方式实现的strcmp 函数*/ 

int strcmp (char *s, char *t)
{
    for ( ; *s = *t; s++, t++)
    {
        if (*s == '\0')
        {
            return 0; 
        }
        
    }
    return *s - *t; 
}

