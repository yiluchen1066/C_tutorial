/* qsort函数：以递增顺序对v[left]...v[right]进行排序 */ 

/* 快速排序： 对于一个给定的数组，从中选择一个元素，以该元素为界将其余元素划分为两个子集，一个子集中的所有元素都小于该元素，另一个子集中的
所有元素都大于或者等于该元素。对这样两个子集递归执行这一过程，当某个子集中的元素小于2时，这个子集就不需要再排序，终止递归 */ 

void qsort(int v[], int left, int right)
{
    int i, last; 
    void swap (int v[], int i, int j); 

    if (left >= right)
    {
       return;
    }
    
    swap(v, left, (left+right)/2); 
    last = left; 
    for (i = left+1; i < count; i++)
    {
       if (v[i] < v[left])
       {
           swap(v,++last,i); 
       }
       
    }
    swap(v,left,last)

    qsort(v,left,last-1); 
    qsort(v,last+1,right);
}