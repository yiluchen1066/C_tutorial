/* getword 函数： 每调用一个这个函数，将读入一个单词， 并将其复制到名字为该函数的第一个参数的数组中，该函数的返回值可能是单词的第一个
字符，文件结束符EOF或者字符本身*/

/* C中有一个运算符sizeof，它可以用来计算任一对象的长度，它将返回一个整形值，它等于指定对象或类型占用的存储空间字节数。sizeof
返回值是无符号整形值，该类型在头文件<stddef.h>*/

#include <ctype.h> 
int getword(char *word, int lim)
{
    int c, getch(void); 
    void ungetch(int); 
    char *w = word; 

    while (isspace(c = getch())) /*跳过空格符*/
    {
        ;
    }
    if (c != EOF)
    {
        *w++ = c;
    }

    if (!isalpha(c))
    {
        *w = '\0'
        return c；
    }
    for ( ; --lim > 0; w++)
    {
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
        
    }
    
    *w = '\0';
    return word[0];



}

/*getword 函数使用的getch函数 （取一个字符）和ungetch函数 （把字符压回到输入中）。当读入的字符不属于字母数字的集合时，
说明getword多读入了一个字符。随后，调用ungetch将多读的一个字符放回到输入中，以便下一次调用使用。
isspace函数跳过空白符，isalpha函数识别字母，isalnum函数识别字母和数字*/