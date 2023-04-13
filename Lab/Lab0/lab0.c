
#include <stdio.h>
int main(void)

{
    printf("Hello, World!\n");

    int x = 0, sum = 0;
    while(x < 200) 
    {
        if(x%2 == 0) 
        {
            sum += x; 
            }
            
        x++;
    }
    printf("%d\n", sum);
    return 0;
}