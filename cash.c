#include <cs50.h>
#include <math.h>
#include <stdio.h>

// I think the tab grader is not functioning

int main(void)
  
{

float d;
    
// get the amount from the user
    do
    {
       d = get_float("Change due: ");
    }
    while (d < 0);
    
    int c = round(d * 100);
int i; 

// start of the greedy algorithm also very concerned for style 50    
    
for (i = 0; c > 0; i++)
{
    if (c >= 25)
    {
        c = (c - 25);
    }
// this should only run if deductible by 10
    else if (c >= 10)
    {
        c = (c - 10);
    }
// this only runs if deductible by 5
    else if (c >= 5)
    {
        c = (c - 5);
    }
// this only runs if deductible by 1
    else if (c >= 1)
    {
        c = (c - 1);
    }

}
printf("%i\n", i);
}
