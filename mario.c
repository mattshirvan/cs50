#include <cs50.h>
#include <stdio.h>

int main(void)

{
	int n;
	int c;
	int j;
	do
	{
		n = get_int("Height: ");
	} 
	while (n < 1 || n > 8);
		c = n;

	for (int i = 0; i < n; i++)
	{		
		for (j = 0; j <= n; j++)
		{
			if (j < c)
				printf(" ");
			else 
				printf("#");						
		}
		c--;
		printf("\n");
	}	
}
