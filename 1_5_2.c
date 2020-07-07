# include <stdio.h>


int main ()
{
    long nc; 
    nc = 0;
    while (getchar () != EOF)
         ++nc;
    printf("%ld\n", nc);
}


/*
int main ()
{
    double nc;
    for (nc = 0; getchar() != EOF; nc = nc+1)
        ;
    printf("%.0f\n",nc);
}
*/




