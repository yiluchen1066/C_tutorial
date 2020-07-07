# include <stdio.h>
int main ()
{
    int c, nl;
    nl = 0;
    while ((c = getchar ()) != EOF)
        if (c == '\n')
            nl = nl +1;
    printf("%d\n", nl);
}

int main ()
{
    int c, ns;
    ns=0;
    while ((c = getchar ()) != EOF)
        if (c == ' ')
            ns = ns + 1;
    printf("%d\n", ns)

}

int main ()
{
    int c, nt;
    while ((c = getchar ()) != EOF)
        if (c == '\t')
            nt = nt +1 ;
    printf("%d\n",nt)

}
