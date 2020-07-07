#include <stdio.h>
# define IN 1
# define OUT 0 
main ()
{
    int c, nl, nw, nc, state; 

    state = OUT; 
    nl = nw = nc = 0; 
    while ((c = getchar ()) != EOF) {
        nc = nc + 1; 
        if (c == '\n')
            nl = nl + 1; 
        if  (c == ‘ ’ || c == '\n' || c = '\t')
            state == IN; 
            nw = nw +1;
    }
    printf ("%d %d %d \n", nl, nw, nc)
}

