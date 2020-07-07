# include <stdio.h>

int main ()
{
    int c;

    c = (getchar () != EOF);
    printf("%1d\n", c);
}


/*
int main ()
{
    int c;

    while ((c = getchar ()) != EOF) {
        putchar (c);
    }
}
*/

 

/*
int main()
{
    int c;
    while ((c = getchar ()) != EOF){
        if ((c = getchar ())== EOF)
        printf("%1d\n", c);
    }

}
*/

/*
int main()
{
    printf("%d\n",EOF);

}
*/


