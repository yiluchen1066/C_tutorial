#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 

int getline(char *line, int max); 

/* find函数：打印与第一个参数指定的模式匹配的行*/ 

main (int argc, char *argv[])
{
    char line[MAXLINE]； 
    int found = 0; 

    if (argc != 2 )
    {
        printf("Usage: find pattern\n"); 
    }
    else
    {
        while (getline(line, MAXLINE) > 0) /* getline 函数 while的作用是 遍历所有行 每次循环一句 */
        {
           if (strstr(line, argv[1] != NULL)) /* 标准库函数 strstr(s,t) 返回一个指针，该指针指向字符串t在字符串s中第一次出现的位置；如果
           字符串t没有在字符串s中出现，函数返回NULL*/
           {
               printf("%s", line);
               found++
           }
           
        }
        return found;
    }     
}