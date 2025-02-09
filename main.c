#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100 /* 操作数或者运算符的最大长度 */ 
main ()
{
    int type; 
    double op2;
    char s[MAXOP]; 

    while ((type = getop(s)) != EOF){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop()+pop());
            break; 
        case '-': 
            op2 = pop();
            push(pop()-op2);
            break;
        case '*':
            push(pop()*pop())
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop()/op2);
            else
            {
                printf("error: zero devisotr\n");
            }
            break; 
        case '\n': 
            printf("\t%.8g\n",pop()); 

        default:
            printf("error: unknown command %s\n",s);
            break;
        }
    }
    return 0;

}

