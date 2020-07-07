/* dcl程序的核心是两个函数，dcl和dirdcl，他们根据声明符的语法对声明进行分析*/

/* dcl函数： 对一个声明符进行语法分析 */ 

void dcl(void)
{
    int ns; 
    
    for ( ns = 0; gettoken() == '*'; ) /* 统计字符的个数 */ 
    {
        ns++;
    }
    dirdcl();
    while (ns-- > 0)
    {
        strcat(out, " pointer to"); /* 标准函数strcat(s,t)， 它将字符串t连接到字符串s的尾部，该函数假定字符串s中有足够的
        空间保存这两个字符串连接的结果*/
    }
    

}

/* dirdcl函数： 分析一个直接声明 */ 
void dirdcl(void)
{
    int type; 

    if (tokenttype == '(')
    {
        /* code */
    }
    
}