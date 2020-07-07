#include <stdio.h>
/* 当fahr=-,20,...,300时，分别打印华氏温度与摄氏温度的对照表 */
int main ()
{
    float fahr, celcius;
    float lower, upper, step;
    lower=0;
    upper=300;
    step=20;
    printf("Fahr vs Ceclius\n");

    fahr=lower;
    while (fahr <= upper) {
        celcius= (5.0 / 9.0) * (fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celcius);
        fahr=fahr+step;
    }
}