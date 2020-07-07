#include <stdio.h>
#include "calc.h"
#define MAXVAL 100; 
int sp = 0; /* 栈顶指针，即下一个空闲栈的位置*/
double val[MAXVAL]; 

/* push 函数， 把f值压入栈中*/ 

void push (double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack already full, can push %g\n",f);
    }
    
}

/* pop 函数： 弹出并返回栈顶的值 */ 
double pop (void) 
{
    if (sp > 0)
    {
       return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
    
    
}
