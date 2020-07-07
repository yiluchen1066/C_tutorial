#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define MAXWORD 100 

/*考虑编写一个程序，它用来统计输入中各个C语言关键字出现的次数。我们需要用一个字符串数组存放关键字名，一个整形数组存放相应
关键字的出现次数。一种实现方法是，使用两个独立的数组keyword和keycoount分别存放他们，这两个数组大小相同，也可以用结构数组
来组织这两个数组，这样多个变量对共同构成一个数组，声明的结构数组如下*/

struct key{
    char *word;
    int count;
};
struct key keytab[NKEYS]; 
/*它声明了一个结构类型key, 并定义了该类型的结构数组keytab，同时为其分配存储空间，数组keytab的每个元素都是一个结构*/

/*在统计关键字出现次数的程序中，我们首先定义了keytab。主程序反复调用
函数getword读取输入，每次读取一个但系。每个单词将通过折半查找函数在keytab中进行查找，关键字列表必须按升序存储在keytab中*/

int getword(char *, int); 
int binsearch(char *, struct key *, int); 

/*主函数： 统计输入C语言关键字的出现次数*/ 

main()
{
    int n; 
    char word[MAXWORD]; 

    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            if ((n = binsearch(word,keytab, NKEYS)) >=0)
            {
                keytab[n].count++;
            }
            
        }
        
    }

    for (n = 0; n < NKEYS; n++)
    {
        if (keytab[n].count >0)
        {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
        
    }
    
    
    return 0;
}

/*binsearch函数，折半查找函数：在tab[0]到tab[n-1]中查找单词*/ 
int binsearch(char *word, struct key keytab[], int n)
{
    int cond; 
    int low, high, middle; 

    low = 0; 
    high = n-1; 
    while (low <= high)
    {
        middle = (low + high)/2; 
        if ((cond = strcmp(word, keytab[middle].word)) < 0)
        {
            high = middle -1; 
        }
        else if (cond > 0)
        {
            low = middle +1;
        }
        else
        {
            return middle;
        }    
    }

    return -1;
    



}



