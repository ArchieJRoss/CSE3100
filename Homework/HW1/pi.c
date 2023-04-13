#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;

	printf("n = ");
	scanf("%d", &n);

	int m = n;
    double p = 1;
	double pi = 0.;
	while(i <= n) {
        for(m = 0; m < i; ++m) {
            p = p * 16.;
        }
        pi += ((4./((8.*i)+1.)) - (2./((8.*i)+4.)) - (1./((8.*i)+5.)) - (1./((8.*i)+6.))) * (1./p);
        p = 1;
        ++i;
    } 
	







	printf("PI = %.10f\n", pi);
	return 0;
}
