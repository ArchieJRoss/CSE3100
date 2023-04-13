#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, t = 0;

	printf("n = ");
	scanf("%d", &n);

	int m = n;
	while(n != 1 && n != 4) {
        while(n != 0) {
            int r;
            r = n % 10; 
            t += r*r;
            n = n/10;
        }
        n = t;
        t = 0;
        printf("%d\n", n);
    }
	

	if(n==1) printf("%d is a happy number.\n", m);
	else printf("%d is NOT a happy number.\n", m);
	return 0;
}
