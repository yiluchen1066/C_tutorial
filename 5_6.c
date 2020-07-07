/* 需要一个程序能够高效，方便地处理可变长度文本行的数据表示方法 
在这个程序中，我们引用指针数组处理这个问题，如果待排序的文本行末尾相连地储存在一个长字符数组中，那么每个文本行可以通过指向他的第一个
字符的指针来访问，这些指针本身可以存储在一个数组中*/

/* 排序过程中包括三个步骤： 读取所有输入行 对文本行进行排序 按次序打印文本行*/ 

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* 进行排序的最大文本行数 */ 

char *lineptr[MAXLINES]; /* 指向文本行的指针数组，lineptr 是一个具有MAXLINES 个元素的一维数组，其中数组的每一个元素是一个指向
字符类型对象的指针。lineptr[i]是一个字符指针，而*lineprt[i]是指该指针指向的第i 个文本行的首字符 */ 

int readlines(char *lineptr[], int nlines); 
void writelines(char *lineptr[], int nlines); 

void qsort(char *lineptr[], int left, int right); 

/* 对输入的文本行进行排序 */ 

main ()
{
    int nlines; 
    if ((nlines = readlines (lineptr, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines-1); 
        writelines(lineptr,nlines); 
        return 0; 
    }
    else
    {
        printf("error: input too big to sort\n"); 
        return 1; 
    }
    
}

#define MAXLEN 1000 /* 每个输入文本行的最大长度 */ 
int getline (char *, int); /* getline 函数的作用是  将行保存到char 中，并返回该行的长度*/
char *alloc(int); 

/* readlines 函数：读取输入行 */
int realines (char * lineptr[],int maxlines)
{
    int len, nlines; 
    char *p, line[MAXLEN]; 
    nlines = 0; 
    while ((len = getline(line, MAXLEN))>0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0'; 
            strcpy(p,line); 
            lineptr(nlines++) = p; 
        }
        
    }
    return nlines; 
}

/* writelines函数；写输出行 */ 
void writelines(char *lineptr[], int nlines)
{
    int i; 
    for (i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
    
}