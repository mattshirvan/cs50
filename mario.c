#include <stdio.h>
#include <cs50.h>

void draw(int pyramid);
int main(void) 
{
    int height;
    do
    {
        height = get_int("Enter a number: ");
    } while (height < 1 || height > 8);
    
    draw(height);
    return 0;
}

void draw(int pyramid)
{
    for (int iterate = 0; iterate < pyramid; iterate++)
    {
        for (int jenga = 0; jenga < pyramid - 1 - iterate; jenga++)
        {
            printf(" ");
        }
        
        for (int jenga = 0; jenga < iterate +1; jenga++)
        {
            printf("#");
        }
        printf("\n");
    }
}
