#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)

{

	float d;
    
    do
    {
       d = get_float("Change due: ");
    }
    while (d < 0);
    
    int c = round(d * 100);
	int i; 
	
	for (i = 0; c > 0; i++)
	{
		if (c >= 25)
		{
			c = (c - 25);
		}

		else if (c >= 10)
		{
			c = (c - 10);
		}

		else if (c >= 5)
		{
			c = (c - 5);
		}

		else if (c >= 1)
		{
			c = (c - 1);
		}
		
	}
	printf("%i\n", i);
}
    
