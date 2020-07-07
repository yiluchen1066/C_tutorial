#include <ctype.h>

/* shellshort 函数 按递增顺序对整型数组v[0], v[1]...v[n-1] 进行排序 
基本思想是 先比较距离较远的元素，而不是像简单交换排序算法那样先比较相邻的元素，这样可以快速减少大量的无序情况，从而减轻后续的工作。被比较的元素之间的距离逐步减小，知道减小为1，这时排序变成了相邻元素的互换。 
该函数中包含一个三重嵌套的for循环，最外层的for语句控制两个被比较元素之间的距离，从n/2开始，逐步进行分析，知道距离为0.中间层的for循环语句用于在元素间移动位置。最内层的for语句用于比较各对相距gap个位置的元素


*/ 

void shellshort (int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0, gap /= 2)
        for (i = gap; i < n, i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap];j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }

}   

