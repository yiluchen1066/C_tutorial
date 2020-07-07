/*设计一个函数： 统计输入中所有单词的出现次数*/

/*因为预先不知道出现的单词列表。一种解决办法是，在读取输入中任意单词的同时，就将它放置到正确的位置，从而
保证所有的单词都是按顺序排列的，我们可以使用二叉树的数据结构来实现*/ 

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100 

struct tnode{ /* 树的节点*/
    char *word; /* 指向单词的指针*/
    int count; /* 单词出现的次数*/
    struct tnode * left; /*左子节点*/
    struct tnode * right; /*右子节点*/
}; 

struct tnode *addtree(struct tnode *, char *); 
void treeprint(struct tnode *);
int getword(char *, int); 

main()
{
    struct tnode * root; 
    char word[MAXWORD]; 

    root = NULL; 
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            root = addtree(root, word);
        }
        
    }
    treeprint(root); 
    return 0; 


}

/*  主函数通过getword读入单词，并通过addtree函数将他们插到树中。addtree函数是递归的。主函数main以参数的方式传递给该函数的一个单词
作为树的最顶层。在每一步中，新单词与节点中存储的单词进行比较，随后通过递归调用addtree转向左子树和右子树。该单词最终将与树中的某节点
匹配 （这种情况下计数值增加1），或者遇到一个空指针。若生成了新节点，返回指向新节点的指针，该指针保存在父节点中。*/

/* addtree函数：在p位置或者p的下方增加一个w节点*/ 

struct tnode * talloc(void);  
char * strdup(char *); 

/*新节点的存储空间由函数talloc获得，返回一个指针，指向能容纳一个树节点的空间*/
/*strdup函数将新单词复制到某个隐藏位置*/

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    if (p == NULL) /*该单词是一个新单词*/
    {
        p = talloc(); /* 创建一个新的节点*/
        p->word = strdup(w); 
        p->count = 1; 
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p-> word)) == 0) /* 新单词与节点中的单词匹配*/
    {
        p->count++;
    }
    else if (cond < 0) /*如果小于该节点中的单词，则进入左子树*/
    {
        p->left = addtree(p->left,w);
    }
    else /*如果大于该节点中的单词，则进入右子树*/
    {
        p->right = addtree(p->right, w);
    }
    return p; 
    
}

/*treepoint 函数按顺序打印树。在每一个节点，他先打印左子树，然后是该单词本身，然后是右子树*/

void treepoint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word); 
        treeprint(p->right);
    }
    
}

/*talloc 函数：创建一个tnode */
#include <stdlib.h>

struct tnode *talloc(void)
{
    return (struct tnode *) malloc (sizeof(struct tnode));
} 

/*strdup函数 把通过其参数传入的字符串复制到某个安全的位置*/

char *strdup(char *s) /* 复制s到某个位置*/
{
    char *p; 

    p = (char *) malloc (strlen(s) + 1)
    if (p != NULL)
    {
        strcpy(p,s); 
    }
    return p; 
    

}



 








