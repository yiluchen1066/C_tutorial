# include <stdio.h>
/*
编写一个程序，来统计各个数字，空白符 （包括空格符， 制表符，以及换行符）以及其他字符出现的次数
*/
int main ()
{
    int c, i, nwhite, nother; 
    int ndigit[10];

    nwhite = 0; 
    nother = 0; 
    for (i = 0; i < 10; i = i+1)
        ndigit[i] = 0; 
    while ((c = getchar ()) != EOF) 
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t' )
            ++nwhite;
        else
            ++nother;
    
    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
    
}