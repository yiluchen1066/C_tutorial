# include <stdio.h>
# define Lower 0
# define Upper 300
# define Step 20
int main ()
{
    int fahr;
    for (fahr= Lower; fahr<= Upper; fahr=fahr+Step)
    printf("%3d %6.1f \n", fahr, (5.0/9.0)*(fahr-32));
}