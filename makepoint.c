/* makepoint函数： 通过x,y坐标构造一个点 */

/* struct 定义了一种数据类型 第一行定义了一个struct point类型的函数，第二行定义了一个 struct point 类型的常量temp*/

struct point makepoint(int x, int y)
{
    struct point temp; 
    {
        temp.x = x;
        temp.y = y;
        return temp;
    };
    
};

struct rect screen; 
struct point middle; 
struct point makepoint(int, int);

screen.p1 = makepoint(0,0); 
screen.p2 = makepoint(XMAX, XMAX); 
middle = makepoint((screen.pt1.x+screen.pt2.x)/2, (screen.pt1.y+screen.pt2.y)/2); 

/* addpoint函数，将两个点相加*/
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1; 

}
/*函数的参数和返回值都是结构类型。之所以直接将相加所得的结果复制给p1，而没有
使用显式的临时变量存储，是为了强调结构类型的参数和其他类型的参数一样，都是通过值传递的*/

