#include <stdio.h>
#include <stdlib.h>

double two_d_random(int n)
{

	//TODO
	//Fill in code below
	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3$ as up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.

    int sqr_size = n * 2 + 1;
    int sqr[sqr_size][sqr_size];
    double num = 0;
    double out = (sqr_size - 2) * (sqr_size - 2);

    
    for (int i = 0; i < sqr_size; i++)
        for (int j = 0; j < sqr_size; j++)
        {
            sqr[i][j] = 0;
        }
    
    int random;
    int x = sqr_size - n - 1 , y = sqr_size - n - 1;
    sqr[x][y] = 1;


    while (1) {
        random = rand() % 4;
        if (random == 0) {
            y = y + 1;
        }
        if (random == 1) {
            x = x + 1;
        }
        if (random == 2) {
            y = y - 1;
        }
        if (random == 3) {
            x = x - 1;
        }
        if (x == 0 || x == (n * 2) || y == 0 || y == (n * 2))  {
            break;
        } else {
            sqr[x][y] = 1;
        }
    }


    for (int z = 0; z < sqr_size; z++)
        for (int c = 0; c < sqr_size; c++)
        {
            if (sqr[z][c] == 1)
                num = num + 1;
        }
    return num / out;
}




//Do not change the code below
int main()
{
	int trials = 1000;

	srand(12345);
	for(int n=1; n<=64; n*=2)
	{	
		double sum = 0.;
		for(int i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3lf\n", n, sum/trials);
	}
	return 0;
}

