#include <stdio.h>
#include <stdlib.h>
#include <ctypoe.h>

#define MAXOP 100 /* 操作数或者运算符的最大长度 */ 
#define NUMBER '0' /* 标识找到一个数 */ 

/* 编写一个具有加减乘除四则运算功能的计算器程序，为了更容易实现，我们在计算器中使用逆波兰表示法代替普通的中缀表示法，在逆波兰表示法中，所有的运算符都跟在操作数的后面
计算器程序的实现很简单，每个操作数一次被压入栈中；当一个运算符到达时， 从 栈中弹出相应数目的操作数 （对于二元运算符来说是两个操作数），
把该运算符作用于弹出的操作数，并把运算结果再压入栈中。到达输入行的末尾时，把栈顶的值弹出并打印*/ 

int getop(char[]); 
void push (double);
double pop (void); /* void 代表函数没有变量，不写void会被误认为函数调用而不是函数声明 */

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

/* getop 函数 获取下一个运算符或操作数 */ 

int getch(void); 
void ungetch(int); 

int getop (char s[])
{
    int i,c; 
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0'; 
    if (!isdigit(c) && c != '.' )
        return c; 
    i = 0; 
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ; 
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
        
    }
    s[i] = '\0'; 
    if(c != EOF)
        ungetch(c); 
    return NUMBER;

}

#define BUFSIZE 100

char buf[BUFSIZE]; 
int bufp = 0; 

int getch (void) /* 取一个字符 可能是压回的字符 */
{
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}

/* getchar() 函数是直接从输入中读字符 */

void ungetch (int c) /* 把字符压回到输入中 */ 
{
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n"); 
    else
    {
        buf[bufp++] = c; 
    }
    
}
