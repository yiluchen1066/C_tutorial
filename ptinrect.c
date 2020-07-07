/* ptinrect 函数判断一个点是否在给定的矩形内部，但是矩形
包括其左侧边和底边，但不包括顶边和右侧边，如果点怕在矩形内，则返回1，否则返回0 */

/* 我们可以用对角线上的两个点来定义矩形*/
struct rect r
{
    struct point pt1;
    struct point pt2; 
};



int ptinrect(struct point p, struct rect r)
{
    return  p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/*传递给指针的结构 */ 

struct point origin, *pp; 

pp = &origin; 
printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
/* 圆括号是必需的*/
/* 简便写法改写上一行 pp是指针 printf("origin is (%d, %d)\n"), pp->x, pp->y); */

/* ++p->len将增加len的值，而不是增加p的值，这是因为其中的隐含括号关系是 ++(p->len).可以使用括号改变结合次序，例如
(++p)->len 先将执行的p的加1操作，再对len执行操作，（p++）-> len则相反*/


