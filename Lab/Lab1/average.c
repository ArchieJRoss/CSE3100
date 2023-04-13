// Only this line of comment is provided 
#include <stdio.h>

int main()
{
    double input = 0, count = 0;
    double average = 0, sum = 0;
    while (scanf("%lf", &input) == 1) 
    {
        count += 1;
        sum += input;
        average = sum/count;
        printf("Total=%f Average=%f\n", sum, average);
    }

    
return 0;
}